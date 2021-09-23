package logica;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author Matheus Alves
 */
public class Main {

    public static void main(String[] args) throws IOException {
        String exp = "";
        int n = 0;
        try { //Para entrar com as outras entradas, basta alterar o "Entrada.in" para o nome da entrada desejada.
            Scanner in = new Scanner(new FileReader("Entrada.in"));
            n = in.nextInt();
            in.nextLine();
            for (int i = 1; i <= n; i++) {
                exp = in.nextLine();
                System.out.println("Problema #" + i);
                if (fnc(exp)) {
                    if (horn(exp)) {
                        char[] lit = arrLit(exp);
                        if (unit(exp)) {
                            System.out.println("Sim, é satisfatível.\n");
                        } else if (satSolver(exp, lit)) {
                            System.out.println("Sim, é satisfatível.\n");
                        } else {
                            System.out.println("Não, não é satisfatível.\n");
                        }
                    } else {
                        System.out.println("Nem todas as cláusulas são de Horn.\n");
                    }
                } else {
                    System.out.println("Não está na FNC.\n");
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage() + "\n\n");
        }
    }

    public static boolean fnc(String exp) {
        int cont = 0;
        for (int i = 0; i < exp.length(); i++) {
            switch (exp.charAt(i)) {
                case '>':
                case '<':
                    return false;
                case '(':
                    cont++;
                    if (cont > 1) {
                        return false;
                    }
                    break;
                case ')':
                    cont = 0;
                    break;
                default:
                    break;
            }
        }
        return true;
    }

    public static boolean horn(String exp) {
        int cont = 0;
        for (int i = 0; i < exp.length(); i++) {
            if (exp.charAt(i) == 'P' || exp.charAt(i) == 'Q' || exp.charAt(i) == 'R' || exp.charAt(i) == 'S') {
                if (exp.charAt(i - 1) != '~') {
                    cont++;
                    if (cont > 1) {
                        return false;
                    }
                }
            } else if (exp.charAt(i) == '(') {
                cont = 0;
            }
        }
        return true;
    }

    public static boolean unit(String exp) {
        for (int i = 0; i < exp.length(); i++) {
            if ((exp.charAt(i) == '(' && exp.charAt(i + 2) == ')') || (exp.charAt(i) == '(' && exp.charAt(i + 3) == ')')) {
                return false;
            }
        }
        return true;
    }

    public static char[] arrLit(String exp) {
        char[] lit = {'M', 'M', 'M', 'M'};
        exp = exp.replaceAll(" ", "");
        String[] clausulas = exp.split("&");
        for (String clausula : clausulas) {
            if (clausula.length() == 3) {
                for (int i = 0; i < lit.length; i++) {
                    if (lit[i] == clausula.charAt(1)) {
                        break;
                    } else if (lit[i] == 'M') {
                        lit[i] = clausula.charAt(1);
                        break;
                    }
                }
            }
        }
        return lit;
    }

    public static boolean satSolver(String exp, char[] lit) {
        exp = exp.replaceAll(" ", "");
        String[] clausulas = exp.split("&");
        for (int i = 0; i < 4; i++) {
            if (lit[i] != 'M') {
                for (int x = 0; x < clausulas.length; x++) {
                    int index = clausulas[x].indexOf(lit[i]);
                    if (clausulas[x].contains(Character.toString(lit[i])) && clausulas[x].charAt(index - 1) != '~') {
                        clausulas[x] = "";
                    } else if (clausulas[x].contains(Character.toString(lit[i])) && clausulas[x].charAt(index - 1) == '~') {
                        String remover = "~" + Character.toString(clausulas[x].charAt(index));
                        clausulas[x] = clausulas[x].replace(remover, "");
                        for (int j = 0; j < clausulas[x].length(); j++) {
                            if(clausulas[x].charAt(j) == 'v' && ((clausulas[x].charAt(j+1) != '~' && clausulas[x].charAt(j+1) != 'P' && clausulas[x].charAt(j+1) != 'Q' && clausulas[x].charAt(j+1) != 'R' && clausulas[x].charAt(j+1) != 'S') || clausulas[x].charAt(j-1) == '(')){
                                char[] myNameChars = clausulas[x].toCharArray();
                                myNameChars[j] = ' ';
                                if(myNameChars[1] == 'v'){
                                    myNameChars[1] = ' ';
                                }
                                clausulas[x] = "";
                                for (int k = 0; k < myNameChars.length; k++) {
                                    if(!Character.toString(myNameChars[k]).equals(" ")){
                                        clausulas[x] += Character.toString(myNameChars[k]);
                                    }else{
                                        j = 0;
                                    }
                                }
                            }
                        }
                        if (clausulas[x].charAt(0) == '(' && clausulas[x].charAt(1) == ')') {
                            return false;
                        } else if (clausulas[x].charAt(0) == '(' && clausulas[x].charAt(2) == ')') {
                            for (int j = 0; j < 4; j++) {
                                if (lit[j] == clausulas[x].charAt(1)) {
                                    break;
                                } else if (lit[j] == 'M') {
                                    lit[j] = clausulas[x].charAt(1);
                                    break;
                                }
                            }
                        }
                        x -= 1;
                    }
                }
            }
        }
        return true;
    }

}
