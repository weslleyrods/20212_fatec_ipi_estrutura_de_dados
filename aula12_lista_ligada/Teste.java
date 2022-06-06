public class Teste {

    static void altera (Integer n) {
        n++;
    }

    public static void main(String[] args) {
        int n = 10;
        altera (Integer.valueOf(n));
        System.out.println(n);
    }
}