import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Type in Alice's secret number (>10): ");
    int aSecretNum = sc.nextInt();
    System.out.println("Type in Bobo's secret number (>10): ");
    int bSecretNum = sc.nextInt();
    sc.nextLine();

    Agent alice = new Agent(aSecretNum);
    Agent bobo = new Agent(bSecretNum);

    alice.performKeyExchange(bobo);

    // pass a message
    System.out.println("Write message: ");
    String msg = sc.nextLine();

    String encryptedMsg = alice.encryptMsg(msg);
    System.out.println("Your message has been encrypted: " + encryptedMsg);
    sc.nextLine();

    String decryptedMsg = bobo.decryptMsg(encryptedMsg);
    System.out.println("Your message has been decrypted: " + decryptedMsg);
    sc.nextLine();
  }
}
