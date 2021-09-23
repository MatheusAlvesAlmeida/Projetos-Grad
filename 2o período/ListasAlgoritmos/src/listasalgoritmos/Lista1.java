package listasalgoritmos;

import java.util.Scanner;

/**
 *
 * @author Matheus Alves
 */
public class Lista1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        Pilha stack = new Pilha();
        PilhaString stack1 = new PilhaString();
        for (int i = 0; i < m; i++) {
            String tipo = in.next();
            String exp = in.next();
            if (tipo.equals("VAL")) {
                for (int j = 0; j < exp.length(); j++) {
                    if (exp.charAt(j) == '0') {
                        stack.push(0);
                    }else if(exp.charAt(j) == '1'){
                        stack.push(1);
                    }else {
                        int op1 = stack.pop();
                        switch (exp.charAt(j)) {
                            case '~':
                                if (op1 == 0) {
                                    stack.push(1);
                                } else {
                                    stack.push(0);
                                }
                                break;
                            case 'v':
                                int op2 = stack.pop();
                                if (op1 == 0 && op2 == 0) {
                                    stack.push(0);
                                } else {
                                    stack.push(1);
                                }
                                break;
                            case '^':
                                int op3 = stack.pop();
                                if (op1 == 1 && op3 == 1) {
                                    stack.push(1);
                                } else {
                                    stack.push(0);
                                }
                                break;
                            default:
                                int op4 = stack.pop();
                                if (op1 == 0 && op4 == 1) {
                                    stack.push(0);
                                } else {
                                    stack.push(1);
                                }
                                break;
                        }
                    }
                }
                System.out.println(stack.pop());
            } else {
                for (int j = 0; j < exp.length(); j++) {
                    if(exp.charAt(j) == '0'){
                        stack1.push("0");
                    }else if(exp.charAt(j) == '1'){
                        stack1.push("1");
                    }else{
                        String t1 = stack1.pop();
                        switch (exp.charAt(j)){
                            case '~':
                                stack1.push("("+"~"+t1+")");
                                break;
                            case 'v':
                                String t2 = stack1.pop();
                                stack1.push("("+t2+"v"+t1+")");
                                break;
                            case '^':
                                String t3 = stack1.pop();
                                stack1.push("("+t3+"^"+t1+")");
                                break;
                            default:
                                String t4 = stack1.pop();
                                stack1.push("("+t4+">"+t1+")");
                                break;
                        }
                    }
                }
                System.out.println(stack1.pop());
            }
        }
    }
}

class Pilha {

    private int valor;
    private Pilha proximo;

    public Pilha() {
        this.valor = -1;
        this.proximo = null;
    }

    public void push(int valor) {
        if (this.valor == -1) {
            Pilha novoElemento = new Pilha();
            novoElemento.valor = valor;
            novoElemento.proximo = this.proximo;
            this.proximo = novoElemento;
        } else {
            this.proximo.push(valor);
        }
    }

    public int pop() {
        int value = 0;
        if (this.valor == -1) {
            value = this.proximo.valor;
            this.proximo = this.proximo.proximo;
        }
        return value;
    }

}

class PilhaString {

    private String valor;
    private PilhaString proximo;

    public PilhaString() {
        this.valor = null;
        this.proximo = null;
    }

    public void push(String valor) {
        if (this.valor == null) {
            PilhaString novoElemento = new PilhaString();
            novoElemento.valor = valor;
            novoElemento.proximo = this.proximo;
            this.proximo = novoElemento;
        } else {
            this.proximo.push(valor);
        }
    }

    public String pop() {
        String value = null;
        if (this.valor == null) {
            value = this.proximo.valor;
            this.proximo = this.proximo.proximo;
        }
        return value;
    }
}
