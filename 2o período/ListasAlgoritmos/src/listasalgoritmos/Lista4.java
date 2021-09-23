package listasalgoritmos;


import java.util.HashMap;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Matheus Alves
 */
public class Lista4 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Vertice v;
        Grafo g = new Grafo();
        String cmd = in.next();
        while (!cmd.equals("END")) {
            switch (cmd) {
                case "REQ":
                    v = new Vertice(in.next());
                    Vertice v2 = new Vertice(in.next());
                    int bolo = g.req(v, v2);
                    if (bolo == 0) {
                        System.out.println("AVAIL");
                    } else {
                        System.out.println("WAIT " + bolo);
                    }
                    break;
                case "FRE":
                    v = new Vertice(in.next());
                    String i = g.fre(v, false);
                    System.out.println("TERM" + i);
                    break;
                default:
                    v = new Vertice(in.next());
                    g.dlk(v);
                    if (g.deadLock == 0) {
                        System.out.println("NONE");
                    } else {
                        String x = g.fre(v, true);
                        System.out.println("KILL " + x);
                        g.deadLock = 0;
                    }
                    g.setarPara0();
                    break;
            }
            cmd = in.next();
        }
    }
}

class Vertice {

    String id;
    LinkedList<Vertice> toApontando;
    LinkedList<Vertice> apontampMim;
    int vis;

    public Vertice(String id) {
        this.id = id;
        this.toApontando = new LinkedList<>();
        this.apontampMim = new LinkedList<>();
        this.vis = 0;
    }

}

class Grafo {

    HashMap<String, Vertice> h;
    //Hashtable<String, Integer> h2;
    int deadLock;

    public Grafo() {
        this.h = new HashMap<>();
        //this.h2 = new Hashtable<>();
        this.deadLock = 0;
    }

    public int req(Vertice v1, Vertice v2) {
        int x = 0;
        if (!this.h.containsKey(v2.id) && !this.h.containsKey(v1.id)) {
            v2.toApontando.add(v1);
            v1.apontampMim.add(v2);
            this.h.put(v2.id, v2);
            this.h.put(v1.id, v1);
        } else if (this.h.containsKey(v2.id) && !this.h.containsKey(v1.id)) {
            Vertice r = this.h.get(v2.id);
            if (r.toApontando.isEmpty()) {
                v1.apontampMim.add(r);
                r.toApontando.add(v1);
            } else {
                v1.toApontando.add(r);
                r.apontampMim.add(v1);
                x = r.apontampMim.size();
            }
            this.h.replace(v2.id, r);
            this.h.put(v1.id, v1);
        } else if (!this.h.containsKey(v2.id) && this.h.containsKey(v1.id)) {
            Vertice p = this.h.get(v1.id);
            v2.toApontando.add(p);
            p.apontampMim.add(v2);
            this.h.replace(v1.id, p);
            this.h.put(v2.id, v2);
        } else {
            Vertice r = this.h.get(v2.id);
            Vertice p = this.h.get(v1.id);
            if (r.toApontando.isEmpty()) {
                r.toApontando.add(p);
                p.apontampMim.add(r);
            } else {
                r.apontampMim.add(p);
                p.toApontando.add(r);
                x = r.apontampMim.size();
            }
            this.h.replace(v2.id, r);
            this.h.replace(v1.id, p);
        }
        return x;
    }

    public String fre(Vertice v1, boolean kill) {
        String retorno = " 0";
        Vertice v = this.h.get(v1.id);
        this.h.remove(v1.id);
        if(kill){
            retorno = v.apontampMim.size() +" "+ v.toApontando.size();
        }else{
            int x = v.apontampMim.size() + v.toApontando.size();
            retorno = " "+x;
        }
        for (int i = 0; i < v.apontampMim.size(); i++) {
            Vertice r = this.h.get(v.apontampMim.get(i).id);
            this.h.remove(v.apontampMim.get(i).id);
            r.toApontando.clear();
            if (!r.apontampMim.isEmpty()) {
                r.toApontando.add(r.apontampMim.getFirst());
                Vertice p1 = r.apontampMim.getFirst();
                p1.toApontando.remove(r);
                p1.apontampMim.add(r);
                this.h.remove(p1.id);
                r.apontampMim.removeFirst();
                this.h.put(p1.id, p1);
            }
            this.h.put(r.id, r);
        }
        for (int i = 0; i < v.toApontando.size(); i++) {
            Vertice r = this.h.get(v.toApontando.get(i).id);
            this.h.remove(r.id);
            r.apontampMim.remove(v);
            this.h.put(r.id, r);
        }
        return retorno;
    }

    public void dlk(Vertice v1) {
        Vertice v = this.h.get(v1.id);
        v.vis = 1;
        this.h.replace(v1.id, v);
        for (int i = 0; i < v.toApontando.size(); i++) {
            if (v.toApontando.get(i).vis == 0) {
                this.dlk(v.toApontando.get(i));
            } else if (v.toApontando.get(i).vis == 1) {
                this.deadLock = 1;
            }
        }
        v.vis = 2;
        this.h.replace(v1.id, v);
    }
    
    public void setarPara0(){
        Set<String> keys = this.h.keySet();
        for(String key : keys){
            Vertice v = this.h.get(key);
            v.vis = 0;
            this.h.replace(key, v);
        }
    }
}
