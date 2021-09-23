/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;

/**
 *
 * @author matheus
 */
public class Song {
    private String artist;
    private String  album;
    private String  title;
    private double duration;

    public Song(String artist, String album, String title, double duration) {
        this.artist = artist;
        this.album = album;
        this.title = title;
        this.duration = duration;
    }

    public String getArtist() {
        return artist;
    }

    public String getAlbum() {
        return album;
    }

    public String getTitle() {
        return title;
    }

    public double getDuration() {
        return duration;
    }
    
}
