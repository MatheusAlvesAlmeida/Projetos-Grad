import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
//
import javax.swing.JButton;
import javax.swing.JToggleButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineEvent;
import javax.sound.sampled.LineListener;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import javax.sound.sampled.Clip;
import javax.swing.JLabel;
import javax.swing.JSlider;

/**
 *
 * @author matheus alves
 */
public class Main extends JFrame implements ActionListener {

    private AudioPlayer player = new AudioPlayer();
    private Thread playbackThread;
    private Thread controlThread;
    private PlayingTimer timer;

    private boolean isPlaying = false;
    private boolean isPause = false;
    private boolean hasStarted = false;
    private boolean needPrev = false;
    private String audioFilePath;
    private String lastOpenPath;

    private JLabel labelFileName = new JLabel("Playing File:");
    private JLabel labelTimeCounter = new JLabel("00:00:00");
    private JLabel labelDuration = new JLabel("00:00:00");

    private JButton buttonPrev = new JButton("Prev");
    private JButton buttonPlay = new JButton("Play");
    private JButton buttonPause = new JButton("Pause");
    private JButton buttonNext = new JButton("Next");
    private JToggleButton buttonRepeat = new JToggleButton();
    private JSlider sliderTime = new JSlider();

    public Main() {
        super("Music Player");
        setLayout(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.insets = new Insets(5, 5, 5, 5);
        constraints.anchor = GridBagConstraints.WEST;

        buttonPrev.setFont(new Font("Sans", Font.BOLD, 14));
        buttonPrev.setText("Prev");
        buttonPrev.setEnabled(true);

        buttonPlay.setFont(new Font("Sans", Font.BOLD, 14));
        buttonPlay.setText("Play");
        buttonPlay.setEnabled(true);

        buttonPause.setFont(new Font("Sans", Font.BOLD, 14));
        buttonPause.setText("Pause");
        buttonPause.setEnabled(false);

        buttonNext.setFont(new Font("Sans", Font.BOLD, 14));
        buttonNext.setText("Next");
        buttonNext.setEnabled(true);

        buttonRepeat.setEnabled(true);

        labelTimeCounter.setFont(new Font("Sans", Font.BOLD, 12));
        labelDuration.setFont(new Font("Sans", Font.BOLD, 12));

        sliderTime.setPreferredSize(new Dimension(400, 20));
        sliderTime.setEnabled(false);
        sliderTime.setValue(0);

        constraints.gridx = 0;
        constraints.gridy = 0;
        constraints.gridwidth = 3;
        add(labelFileName, constraints);

        constraints.anchor = GridBagConstraints.CENTER;
        constraints.gridy = 1;
        constraints.gridwidth = 1;
        add(labelTimeCounter, constraints);

        constraints.gridx = 1;
        add(sliderTime, constraints);

        constraints.gridx = 2;
        add(labelDuration, constraints);

        JPanel panelButtons = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 5));
        panelButtons.add(buttonPrev);
        panelButtons.add(buttonPlay);
        panelButtons.add(buttonPause);
        panelButtons.add(buttonNext);
        panelButtons.add(buttonRepeat);
        constraints.gridwidth = 3;
        constraints.gridx = 0;
        constraints.gridy = 2;
        add(panelButtons, constraints);

        buttonPlay.addActionListener(this);
        buttonPause.addActionListener(this);
        buttonNext.addActionListener(this);
        buttonPrev.addActionListener(this);
        buttonRepeat.addActionListener(this);
        pack();
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        Object source = event.getSource();
        if (source instanceof JButton) {
            JButton button = (JButton) source;
            if (button == buttonPlay) {
                if (!isPlaying) {
                    if (hasStarted) {
                        playBack();
                    } else {
                        init();
                    }
                } else {
                    stopPlaying();
                }
            } else if (button == buttonPause) {
                if (!isPause) {
                    pausePlaying();
                } else {
                    resumePlaying();
                }
            } else if (button == buttonPrev) {
                prevPlay();
            } else if (button == buttonNext) {
                nextPlay();
            }

        }
    }

    private void playBack() {
        timer = new PlayingTimer(labelTimeCounter, sliderTime);
        timer.start();
        isPlaying = true;

        playbackThread = new Thread(new Runnable() {

            @Override
            public void run() {
                try {
                    buttonPlay.setText("Stop");
                    buttonPlay.setEnabled(true);
                    buttonPause.setText("Pause");
                    buttonPause.setEnabled(true);

                    player.load(audioFilePath);
                    timer.setAudioClip(player.getAudioClip());
                    labelFileName.setText("Playing File: " + audioFilePath);
                    sliderTime.setMaximum((int) player.getClipSecondLength());

                    labelDuration.setText(player.getClipLengthString());
                    player.play();

                    resetControls();

                } catch (UnsupportedAudioFileException ex) {
                    JOptionPane.showMessageDialog(Main.this,
                            "The audio format is unsupported!", "Error", JOptionPane.ERROR_MESSAGE);
                    resetControls();
                    ex.printStackTrace();
                } catch (LineUnavailableException ex) {
                    JOptionPane.showMessageDialog(Main.this,
                            "Could not play the audio file because line is unavailable!", "Error", JOptionPane.ERROR_MESSAGE);
                    resetControls();
                    ex.printStackTrace();
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(Main.this,
                            "I/O error while playing the audio file!", "Error", JOptionPane.ERROR_MESSAGE);
                    resetControls();
                    ex.printStackTrace();
                }

            }
        });

        playbackThread.start();
    }

    private void stopPlaying() {
        isPause = false;
        buttonPause.setText("Pause");
        buttonPause.setEnabled(false);
        timer.reset();
        timer.interrupt();
        player.stop();
        playbackThread.interrupt();
    }

    private void pausePlaying() {
        buttonPause.setText("Resume");
        isPause = true;
        player.pause();
        timer.pauseTimer();
        playbackThread.interrupt();
    }

    private void resumePlaying() {
        buttonPause.setText("Pause");
        isPause = false;
        player.resume();
        timer.resumeTimer();
        playbackThread.interrupt();
    }

    private void resetControls() {
        timer.reset();
        timer.interrupt();

        buttonPlay.setText("Play");

        buttonPause.setEnabled(false);

        isPlaying = false;
    }

    private void nextPlay() {
        timer.reset();
        player.stop();
        isPlaying = false;
        playbackThread.interrupt();
        controlThread.interrupt();
        buttonPlay.setText("Stop");
        buttonPlay.setEnabled(true);
        buttonPause.setText("Pause");
        buttonPause.setEnabled(true);
        player.resume();
        timer.start();
        isPlaying = true;
    }

    private void prevPlay() {
        needPrev = true;
        timer.reset();
        player.stop();
        isPlaying = false;
        playbackThread.interrupt();
        controlThread.interrupt();
        buttonPlay.setText("Stop");
        buttonPlay.setEnabled(true);
        buttonPause.setText("Pause");
        buttonPause.setEnabled(true);
        player.resume();
        timer.start();
        isPlaying = true;
    }

    private void init() {
        hasStarted = true;
        BufferedReader br = null;
        final DLinkedList playList = new DLinkedList();
        try {

            FileInputStream fstream = new FileInputStream("playlist.txt");
            br = new BufferedReader(new InputStreamReader(fstream));
            String line;
            while ((line = br.readLine()) != null) {
                playList.insert(line);
            }
            controlThread = new Thread(new Runnable() {
                Node temp = playList.first;

                @Override
                public void run() {
                    while (temp != null) {
                        audioFilePath = temp.getData();
                        playBack();
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        try {
                            Thread.sleep(player.getClipSecondLength() * 1000 + 500);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        if (buttonRepeat.isSelected()) {
                            playList.last.setNext(playList.first);
                            playList.first.setPrev(playList.last);
                        } else {
                            playList.first.setPrev(null);
                            playList.last.setNext(null);
                        }
                        System.out.println("Changed list");
                        if (!needPrev) {
                            temp = temp.getNext();
                        } else {
                            temp = temp.getPrev();
                            needPrev = false;
                        }
                    }
                }
            });
            controlThread.start();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {

        try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        SwingUtilities.invokeLater(new Runnable() {

            @Override
            public void run() {
                new Main().setVisible(true);
            }
        });
    }

}

class AudioPlayer implements LineListener {

    private static final int SECONDS_IN_HOUR = 60 * 60;
    private static final int SECONDS_IN_MINUTE = 60;

    private boolean playCompleted;

    private boolean isStopped;

    private boolean isPaused;

    private Clip audioClip;

    public void load(String audioFilePath)
            throws UnsupportedAudioFileException, IOException,
            LineUnavailableException {
        File audioFile = new File(audioFilePath);

        AudioInputStream audioStream = AudioSystem
                .getAudioInputStream(audioFile);

        AudioFormat format = audioStream.getFormat();

        DataLine.Info info = new DataLine.Info(Clip.class, format);

        audioClip = (Clip) AudioSystem.getLine(info);

        audioClip.addLineListener(this);

        audioClip.open(audioStream);
    }

    public long getClipSecondLength() {
        return audioClip.getMicrosecondLength() / 1_000_000;
    }

    public String getClipLengthString() {
        String length = "";
        long hour = 0;
        long minute = 0;
        long seconds = audioClip.getMicrosecondLength() / 1_000_000;

        System.out.println(seconds);

        if (seconds >= SECONDS_IN_HOUR) {
            hour = seconds / SECONDS_IN_HOUR;
            length = String.format("%02d:", hour);
        } else {
            length += "00:";
        }

        minute = seconds - hour * SECONDS_IN_HOUR;
        if (minute >= SECONDS_IN_MINUTE) {
            minute = minute / SECONDS_IN_MINUTE;
            length += String.format("%02d:", minute);

        } else {
            minute = 0;
            length += "00:";
        }

        long second = seconds - hour * SECONDS_IN_HOUR - minute * SECONDS_IN_MINUTE;

        length += String.format("%02d", second);

        return length;
    }

    void play() throws IOException {

        audioClip.start();

        playCompleted = false;
        isStopped = false;

        while (!playCompleted) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
                if (isStopped) {
                    audioClip.stop();
                    break;
                }
                if (isPaused) {
                    audioClip.stop();
                } else {
                    audioClip.start();
                }
            }
        }

        audioClip.close();

    }

    public void stop() {
        isStopped = true;
    }

    public void pause() {
        isPaused = true;
    }

    public void resume() {
        isPaused = false;
    }

    @Override
    public void update(LineEvent event) {
        LineEvent.Type type = event.getType();
        if (type == LineEvent.Type.STOP) {
            System.out.println("STOP EVENT");
            if (isStopped || !isPaused) {
                playCompleted = true;
            }
        }
    }

    public Clip getAudioClip() {
        return audioClip;
    }

}

class DLinkedList {

    Node first;
    Node last;

    void insert(String v) {
        Node p = new Node();
        p.setData(v);
        if (first == null) {
            p.setPrev(null);
            first = p;
            last = p;
        } else {
            Node q = first;
            while (q.getNext() != null) {
                q = q.getNext();
            }
            q.setNext(p);
            p.setPrev(q);
            last = p;
        }
    }

    void Traverse() {
        Node temp = first;
        System.out.println("Ascending Traverse");
        while (temp != null) {
            System.out.println(temp.getData());
            temp = temp.getNext();
        }
        /*
		temp = last;
		System.out.println("Descending Traverse");
		while(temp != null)
		{
			System.out.println(temp.getData());
			temp = temp.getPrev();
		}
         */
    }

    void delete(String v) {
        Node q = first;
        while (q.getNext() != null) {
            if ((q.getPrev() == null) && (q.getData() == v)) {
                q.getNext().setPrev(q.getPrev());
                first = q.getNext();
                break;
            } else {
                if (q.getData() == v) {
                    q.getPrev().setNext(q.getNext());
                    q.getNext().setPrev(q.getPrev());
                    break;
                }
            }

            q = q.getNext();
        }
        if (q.getNext() == null && q.getData() == v) {
            last = q.getPrev();
            last.setNext(null);
        }
    }

}

class Node {

    Node next;
    Node prev;
    String data;

    void setData(String v) {
        data = v;
    }

    void setNext(Node n) {
        next = n;
    }

    String getData() {
        return data;
    }

    Node getNext() {
        return next;
    }

    void setPrev(Node n) {
        prev = n;
    }

    Node getPrev() {
        return prev;
    }
}

class PlayingTimer extends Thread {

    private DateFormat dateFormater = new SimpleDateFormat("HH:mm:ss");
    private boolean isRunning = false;
    private boolean isPause = false;
    private boolean isReset = false;
    private boolean isRepeat = false;
    private long startTime;
    private long pauseTime;

    private JLabel labelRecordTime;
    private JSlider slider;
    private Clip audioClip;

    public void setAudioClip(Clip audioClip) {
        this.audioClip = audioClip;
    }

    PlayingTimer(JLabel labelRecordTime, JSlider slider) {
        this.labelRecordTime = labelRecordTime;
        this.slider = slider;
    }

    public void run() {
        isRunning = true;

        startTime = System.currentTimeMillis();

        while (isRunning) {
            try {
                Thread.sleep(100);
                if (!isPause) {
                    if (audioClip != null && audioClip.isRunning()) {
                        labelRecordTime.setText(toTimeString());
                        int currentSecond = (int) audioClip.getMicrosecondPosition() / 1_000_000;
                        slider.setValue(currentSecond);
                    }
                } else {
                    pauseTime += 100;
                }
            } catch (InterruptedException ex) {
                ex.printStackTrace();
                if (isReset) {
                    slider.setValue(0);
                    labelRecordTime.setText("00:00:00");
                    isRunning = false;
                    break;
                }
            }
        }
    }

    void reset() {
        isReset = true;
        isRunning = false;
    }

    void pauseTimer() {
        isPause = true;
    }

    void resumeTimer() {
        isPause = false;
    }

    void repeatSong() {
        isRepeat = true;
    }

    private String toTimeString() {
        long now = System.currentTimeMillis();
        Date current = new Date(now - startTime - pauseTime);
        dateFormater.setTimeZone(TimeZone.getTimeZone("GMT"));
        String timeCounter = dateFormater.format(current);
        return timeCounter;
    }
}
