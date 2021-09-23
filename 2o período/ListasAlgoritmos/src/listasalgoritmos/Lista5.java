package listasalgoritmos;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Matheus Alves
 */
public class Lista5 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t, n, m;
        Vertex[] arrVertex;
        ArrayList<Edge> edges = new ArrayList<>();
        t = in.nextInt();
        for (int i = 0; i < t; i++) {
            n = in.nextInt();
            arrVertex = new Vertex[n];
            for (int j = 0; j < n; j++) {
                arrVertex[j] = new Vertex(in.nextInt(), in.nextInt());
            }
            m = in.nextInt();
            for (int j = 0; j < m; j++) {
                int k = in.nextInt();
                arrVertex[k].coin = true;
            }
            for (int j = 0; j < n; j++) {
                if (j == n) {
                    in.nextInt();
                } else {
                    Vertex v1 = arrVertex[j];
                    int dj = in.nextInt();
                    for (int k = 0; k < dj; k++) {
                        int x = in.nextInt();
                        Vertex v2 = arrVertex[x];
                        double weight = Math.pow((v2.x - v1.x), 2) + Math.pow((v2.y - v1.y), 2);
                        if (v2.coin) {
                            weight *= -1;
                        }
                        edges.add(new Edge(weight, j, x));
                    }
                }
            }
            bestPath(arrVertex, edges, arrVertex[0]);
            System.out.println();
            edges.clear();
        }

    }

    public static void bestPath(Vertex[] vl, ArrayList<Edge> el, Vertex startPoint) {
        double distances[] = new double[vl.length];
        int precursors[] = new int[vl.length];
        int qtePre[] = new int[vl.length];
        for (int i = 0; i < vl.length; i++) {
            if (vl[i] == startPoint) {
                distances[i] = 0;
            } else {
                distances[i] = vl[i].minDist;
            }
            precursors[i] = -1;
            qtePre[i] = 0;
        }
        for (int i = 0; i < vl.length - 1; i++) {
            for (int x = el.size() - 1; x >= 0; x--) {
                if (distances[el.get(x).starting] + el.get(x).weight < distances[el.get(x).target]) {
                    distances[el.get(x).target] = distances[el.get(x).starting] + el.get(x).weight;
                    precursors[el.get(x).target] = el.get(x).starting;
                    qtePre[el.get(x).target] =  1 + qtePre[el.get(x).starting];
                }else if(distances[el.get(x).starting] + el.get(x).weight == distances[el.get(x).target]){
                    if(qtePre[el.get(x).starting] + 1 < qtePre[el.get(x).target]){
                        precursors[el.get(x).target] = el.get(x).starting;
                        qtePre[el.get(x).target] =  1 + qtePre[el.get(x).starting];
                    } else if (qtePre[el.get(x).starting] + 1 == qtePre[el.get(x).target]) {
                        if (el.get(x).starting <= precursors[el.get(x).target]) {
                            precursors[el.get(x).target] = el.get(x).starting;
                            qtePre[el.get(x).target] = 1 + qtePre[el.get(x).starting];
                        }
                    }                   
                }   
            }
        }
        for (Edge edge : el) {
            if (distances[edge.starting] + edge.weight < distances[edge.target]) {
                System.out.print("LOOP");
                return;
            }
        }
        System.out.print((int) distances[distances.length - 1] + " ");
        findPrecursors(precursors, vl.length - 1, new ArrayList<>());
    }

    public static void findPrecursors(int[] precursors, int index, ArrayList<Integer> path) {
        path.add(index);
        if (index == 0) {
            for (int i = path.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    System.out.print(path.get(i));
                } else {
                    System.out.print(path.get(i) + " ");
                }
            }
            return;
        }
        findPrecursors(precursors, precursors[index], path);
    }
}

class Vertex {    
    int x;
    int y;
    boolean coin;
    double minDist = Double.MAX_VALUE;

    public Vertex(int x, int y) {
        this.x = x;
        this.y = y;
        this.coin = false;
    }
}

class Edge {

    double weight;
    int starting;
    int target;

    public Edge(double weight, int starting, int target) {
        this.weight = weight;
        this.starting = starting;
        this.target = target;
    }

}
