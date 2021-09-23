package listasalgoritmos;

import java.util.Scanner;

/**
 *
 * @author Matheus Alves
 */
public class Lista2 {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int mMin = in.nextInt();
        int fMin = in.nextInt();
        int fMax = in.nextInt();
        int maior = 0, maior2 = 0;
        int[] arr = {1, 26, 676, 17576, 456976, 11881376};
        boolean n = true;
        in.nextLine();
        Estacionamento1 tabela = new Estacionamento1(mMin);
        Estacionamento2 e2 = new Estacionamento2(mMin);
        String comando = "";
        do {
            comando = in.nextLine();
            if (!comando.equals("END")) {
                String[] partes = comando.split(" ");
                String parte0 = partes[0];
                String parte1 = partes[1];
                int chave = calcChave(parte1, arr);
                if (parte0.equals("IN")) {
                    tabela.in(chave, fMax);
                    e2.in(chave, fMax);
                } else if (parte0.equals("OUT")) {
                    tabela.out(chave, fMin, mMin);
                    e2.out(chave, fMin, mMin);
                } else {
                    n = tabela.sch(chave, false);
                    if(n){
                        maior2 = e2.sch(chave, false, maior2);
                    }                    
                }
            }
        } while (!comando.equals("END"));
        System.out.println(tabela.getdMax() + " " + maior2);
    }
    
    public static int calcChave(String placa, int[] arr) {
        int[] p = new int[6];
        int chave = 0;
        for (int i = 0; i < placa.length(); i++) {
            p[i] = (int) placa.charAt(i) - 65;
            chave += p[i] * arr[i];
        }
        return chave;
    }
    
}

class Estacionamento1 {
    
    private int mVagas;
    private int vagasOcp;
    private int vagasEfetivas;
    private int[] vagas;
    private int dMax;

    public int getdMax() {
        return dMax;
    }
    
    public Estacionamento1(int mVagas) {
        this.mVagas = mVagas;
        this.vagasOcp = 0;
        this.vagas = new int[mVagas];
        this.vagasEfetivas = vagasOcp;
        this.dMax = 0;
    }
    
    public void in(int chave, int fMax) {
        int j = 0;
        if (100 * this.vagasOcp > fMax * this.mVagas) {
            this.mVagas *= 2;
            int[] aux = new int[this.mVagas];
            int total = this.vagas.length;
            for (int i = 0; i < total; i++) {
                if (this.vagas[i] != 0 && this.vagas[i] != -1) {
                    int x = 0;
                    boolean ok = true;
                    while (ok) {
                        if (aux[(this.vagas[i] + x) % this.mVagas] == 0) {
                            aux[(this.vagas[i] + x) % this.mVagas] = this.vagas[i];
                            ok = false;
                        } else {
                            x++;
                        }
                    }
                }
            }
            this.vagas = aux;
            this.vagasOcp = this.vagasEfetivas;
        }
        if (this.vagas[chave % this.mVagas] != 0) {
            boolean ok = true;
            j = 1;
            while (ok) {
                if (this.vagas[(chave + j) % this.mVagas] != 0) {
                    j++;
                } else {
                    ok = false;
                }
            }
        }
        this.vagasOcp++;
        this.vagas[(chave + j) % this.mVagas] = chave;
        this.vagasEfetivas++;
        
        System.out.print((chave + j) % this.mVagas);
        System.out.print(" " + j + " ");
    }
    
    public void out(int chave, int fMin, int mMin) {
        boolean n = this.sch(chave, true);
        if(n != false){
            if (this.mVagas > mMin && 100 * this.vagasEfetivas < this.mVagas * fMin) {
                this.mVagas = this.mVagas / 2;
                int[] aux = new int[this.mVagas];
                int total = this.vagas.length;
                for (int i = 0; i < total; i++) {
                    if (this.vagas[i] != 0 && this.vagas[i] != -1) {
                        int x = 0;
                        boolean ok = true;
                        while (ok) {
                            if (aux[(this.vagas[i] + x) % this.mVagas] == 0) {
                                aux[(this.vagas[i] + x) % this.mVagas] = this.vagas[i];
                                ok = false;
                            } else {
                                x++;
                            }
                        }
                    }
                }
                this.vagas = aux;
                this.vagasOcp = this.vagasEfetivas;
            }
        }
    }
    
    public boolean sch(int chave, boolean out) {
        int i = 0;
        if (this.vagas[chave % this.mVagas] == chave) {
            System.out.print(chave % this.mVagas + " 0 ");
            if (out) {
                this.vagas[chave % this.mVagas] = -1;
                this.vagasEfetivas--;
            }
            return true;
        } else if (this.vagas[chave % this.mVagas] == 0) {
            System.out.println("-1 -1 -1 -1");
            if(out){
                return false;
            }
        } else {
            boolean ok = true;
            i = 1;
            while (ok) {
                if (this.vagas[(chave + i) % this.mVagas] != chave && this.vagas[(chave + i) % this.mVagas] != 0) {
                    i++;
                } else if (this.vagas[(chave + i) % this.mVagas] == chave) {
                    System.out.print((chave + i) % this.mVagas);
                    System.out.printf(" %d ", i);
                    if (out) {
                        this.vagas[(chave + i) % this.mVagas] = -1;
                        this.vagasEfetivas--;
                    }else{
                        if (i > this.dMax) {
                            this.dMax = i;
                        }
                    }                    
                    return true;
                } else {
                    System.out.println("-1 -1 -1 -1");
                    if(out) {
                        return false;
                    }
                    ok = false;
                }
            }
        }
        return false;
    }
}

class Estacionamento2 {
    
    private int mVagas;
    private int vagasOcp;
    private int vagasEfetivas;
    private int[] vagas;
    private int[] dist;
    
    public Estacionamento2(int mVagas) {
        this.mVagas = mVagas;
        this.vagasOcp = 0;
        this.vagas = new int[mVagas];
        this.dist = new int[mVagas];
        this.vagasEfetivas = vagasOcp;
    }
    
    public void in(int chave, int fMax) {
        int j = 0;
        boolean gambiarra = true;
        if (100 * this.vagasOcp > fMax * this.mVagas) {
            int[] aux = this.vagas;
            this.mVagas *= 2;
            this.vagas = new int[this.mVagas];
            this.dist = new int[this.mVagas];
            int total = aux.length;
            for (int i = 0; i < total; i++) {
                if (aux[i] != 0 && aux[i] != -1) {
                    int x = 0;
                    boolean ok = true;
                    while (ok) {
                        if (this.vagas[(aux[i] + x) % this.mVagas] == 0) {
                            this.vagas[(aux[i] + x) % this.mVagas] = aux[i];
                            this.dist[(aux[i] + x) % this.mVagas] = x;
                            ok = false;
                        } else {
                            if (x <= this.dist[(aux[i] + x) % this.mVagas]) {
                                x++;
                            } else {
                                int auxChave = this.vagas[(aux[i] + x) % this.mVagas];
                                int auxDist = this.dist[(aux[i] + x) % this.mVagas];
                                this.vagas[(aux[i] + x) % this.mVagas] = aux[i];
                                this.dist[(aux[i] + x) % this.mVagas] = x;
                                aux[i] = auxChave;
                                x = auxDist + 1;
                            }
                        }
                    }
                }
            }
            this.vagasOcp = this.vagasEfetivas;
        }
        if (this.vagas[(chave + j) % this.mVagas] == 0){
            this.vagas[(chave + j) % this.mVagas] = chave;
            this.dist[(chave + j) % this.mVagas] = j;
            System.out.print((chave + j) % this.mVagas);
            System.out.println(" " + j);
            this.vagasOcp++;
            this.vagasEfetivas++;
        }else{
            j = 1;
            boolean ok = true;
            while (ok) {
                if (this.vagas[(chave + j) % this.mVagas] == 0) {
                    this.vagas[(chave + j) % this.mVagas] = chave;
                    this.dist[(chave + j) % this.mVagas] = j;
                    if(gambiarra) {
                        System.out.print((chave + j) % this.mVagas);
                        System.out.println(" " + j);
                        this.vagasOcp++;
                        this.vagasEfetivas++;
                        gambiarra = false;
                    }
                    ok = false;
                } else if(this.vagas[(chave + j) % this.mVagas] == -1){
                    j++;
                }else {
                    if (j <= this.dist[(chave + j) % this.mVagas]) {
                        j++;
                    } else {
                        int auxChave = this.vagas[(chave + j) % this.mVagas];
                        int auxDist = this.dist[(chave + j) % this.mVagas];
                        this.vagas[(chave + j) % this.mVagas] = chave;
                        this.dist[(chave + j) % this.mVagas] = j;
                        if (gambiarra) {
                            System.out.print((chave + j) % this.mVagas);
                            System.out.println(" " + j);
                            this.vagasOcp++;
                            this.vagasEfetivas++;
                            gambiarra = false;
                        }
                        chave = auxChave;
                        j = auxDist++;
                    }
                }
            }
        }
    }
    
    public void out(int chave, int fMin, int mMin) {
        int n = this.sch(chave, true, 0);
        if (n != -10) {
            if (this.mVagas > mMin && 100 * this.vagasEfetivas < this.mVagas * fMin) {
                this.mVagas = this.mVagas / 2;
                int[] aux = this.vagas;
                this.vagas = new int[this.mVagas];
                this.dist = new int[this.mVagas];
                int total = aux.length;
                for (int i = 0; i < total; i++) {
                    if (aux[i] != 0 && aux[i] != -1) {
                        int x = 0;
                        boolean ok = true;
                        while (ok) {
                            if (this.vagas[(aux[i] + x) % this.mVagas] == 0) {
                                this.vagas[(aux[i] + x) % this.mVagas] = aux[i];
                                this.dist[(aux[i] + x) % this.mVagas] = x;
                                ok = false;
                            } else {
                                if (x <= this.dist[(aux[i] + x) % this.mVagas]) {
                                    x++;
                                } else {
                                    int auxChave = this.vagas[(aux[i] + x) % this.mVagas];
                                    int auxDist = this.dist[(aux[i] + x) % this.mVagas];
                                    this.vagas[(aux[i] + x) % this.mVagas] = aux[i];
                                    this.dist[(aux[i] + x) % this.mVagas] = x;
                                    aux[i] = auxChave;
                                    x = auxDist + 1;
                                }
                            }
                        }
                    }
                }
                this.vagasOcp = this.vagasEfetivas;
            }
        }
    }
    
    public int sch(int chave, boolean out, int dMax) {
        int i = 0;
        if (this.vagas[chave % this.mVagas] == chave) {
            System.out.println(chave % this.mVagas + " 0");
            if (out == true) {
                this.vagas[chave % this.mVagas] = -1;
                this.vagasEfetivas--;
            }
        } else if (this.vagas[chave % this.mVagas] == 0) {
            if(out){
                return -10;
            }
        } else {
            boolean ok = true;
            i = 1;
            while (ok) {
                if (this.vagas[(chave + i) % this.mVagas] == -1) {
                    i++;
                }else if(this.vagas[(chave + i) % this.mVagas] == 0){
                    if (out) {
                        return -10;
                    }
                    ok = false;
                } else if (this.vagas[(chave + i) % this.mVagas] != chave && this.dist[(chave + i) % this.mVagas] < i) {
                    if (out) {
                        return -10;
                    }
                    ok = false;
                } else if (this.vagas[(chave + i) % this.mVagas] == chave) {
                    System.out.print((chave + i) % this.mVagas);
                    System.out.printf(" %d\n", i);
                    if (out == true) {
                        this.vagas[(chave + i) % this.mVagas] = -1;
                        this.vagasEfetivas--;
                    }
                    if (i > dMax) {
                        dMax = i;
                    }
                    return dMax;
                } else {
                    i++;
                }
            }
        }
        return dMax;
    }
}
