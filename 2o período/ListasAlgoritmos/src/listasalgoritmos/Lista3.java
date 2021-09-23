package listasalgoritmos;

import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author maa4
 */
public class Lista3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), h = in.nextInt(), f = in.nextInt(), x = 0;
        int caste, id, base;
        Node sla = new Node(1);
        String comando = "";
        Node[] bases = new Node[n];   
        Pair<Node, Integer, Node> result;
        for (int i = 0; i < f; i++) {
            comando = in.next();
            caste = in.nextInt();
            id = in.nextInt();
            base = in.nextInt();    
            for (int j = 0; j < n; j++) {
                result = sla.insert(bases[(base + j) % n], id, caste, h, 0);
                bases[(base + j) % n] = result.first;  
                if(result.second == 1){
                    j = n;
                }
            }                      
        }
        do {            
            comando = in.next();
            if (!comando.equals("END")) {
                caste = in.nextInt();
                id = in.nextInt();
                base = in.nextInt();
                if (comando.equals("INF")) {
                    for (int j = 0; j < n; j++) {
                        result = sla.insert(bases[(base + j) % n], id, caste, h, 0);
                        bases[(base + j) % n] = result.first;
                        if (result.second == 1) {
                            System.out.println((base + j) % n);
                            j = n;
                        }else if (j == n - 1 && result.second == 0) {
                            System.out.println("-1");
                        }
                    }
                } else if (comando.equals("EXT")) {
                    bases[base] = sla.delete(bases[base], caste, id);
                } else {
                    System.out.println(sla.search(bases[base], 0, id, caste));
                }
            }            
        } while (!comando.equals("END"));
    }
}

class Node{
    Node left, right;
    int num;
    LinkedList<Integer> list;
    
    public Node(int num) {
        this.left = null;
        this.right = null;
        this.list = new LinkedList<>();
        this.num = num;
    }
    
    public Pair<Node, Integer, Node> insert(Node root, int id, int caste, int hMax, int level){
        if(root == null){
            if(level >= hMax){
                return new Pair (null, 0, null);
            }
            Node novo = new Node(caste);
            novo.list.add(id);
            return new Pair (novo, 1, null);
        }else if(caste < root.num){
            Pair<Node, Integer, Node> result = insert(root.left, id, caste, hMax, level + 1);
            root.left = result.first;
            return new Pair (root, result.second, null);
        }else if(caste > root.num){
            Pair<Node, Integer, Node> result = insert(root.right, id, caste, hMax, level + 1);
            root.right = result.first;
            return new Pair (root, result.second, null);
        }else{
            root.list.add(id);
            return new Pair (root, 1, null);
        }
    }
    
    public int search(Node root, int level, int id, int caste){
        if(root == null){
            return -1;
        }else if(root.list.contains(id)){
            return level;
        }else if(caste < root.num){
            return search(root.left, level+1, id, caste);
        }else{
            return search(root.right, level+1, id, caste);
        }
    }
    
    public Pair<Node, Integer, LinkedList> deleteMin(Node root) {
        if (root.left == null) {
            return new Pair(root.right, root.num, root.list);
        } else {
            Pair<Node, Integer, LinkedList> result = deleteMin(root.left);
            root.left = result.first;
            return new Pair(root, result.second, root.list);
        }
    }
    
    public Node delete(Node root, int caste, int id) {
        if (root == null) {
            return null;
        } else if (caste < root.num) {
            root.left = delete(root.left, caste, id);
            return root;
        } else if (caste > root.num) {
            root.right = delete(root.right, caste, id);
            return root;
        } else {
            root.list.remove(new Integer(id));
            if (root.list.isEmpty()) {
                if (root.left == null) {
                    root = root.right;
                    return root;
                } else if (root.right == null) {
                    root = root.left;
                    return root;
                } else {
                    Pair<Node, Integer, LinkedList> result = deleteMin(root.right);
                    root.right = result.first;
                    root.num = result.second;
                    root.list = result.third;
                    return root;
                }
            }
            return root;
        }
    }
}

class Pair<T, U, W> {
    public T first;
    public U second;
    public W third;
    public Pair(T t, U u, W w) { 
        first = t; 
        second = u; 
        third = w;
    }    
    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }
}