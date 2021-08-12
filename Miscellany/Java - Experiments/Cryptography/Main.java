import java.util.Scanner;
import java.nio.charset.StandardCharsets;

public class Main {

  static Scanner sc = new Scanner(System.in);

  private static void passAStringMessage(Agent a, Agent b, String msg) {
    String encryptedMsg = a.encryptMsg(msg);
    System.out.println("Your message has been encrypted: " + encryptedMsg);
    sc.nextLine();

    String decryptedMsg = b.decryptMsg(encryptedMsg);
    System.out.println("Your message has been decrypted: " + decryptedMsg);
    sc.nextLine();
  }


  private static void passAByteArrayMessage(Agent a, Agent b, String msg) {
    byte[] encryptedMsg = a.encryptMsg(msg.getBytes(StandardCharsets.UTF_8));
    System.out.println("Your message has been encrypted: " + encryptedMsg);
    sc.nextLine();

    byte[] decryptedMsg = b.decryptMsg(encryptedMsg);
    System.out.println("Your message has been decrypted: " + new String(decryptedMsg, StandardCharsets.UTF_8));
    sc.nextLine();
  }


  public static void main(String[] args) {
    System.out.println("Type in Alice's secret number (>2): ");
    int aSecretNum = sc.nextInt();
    System.out.println("Type in Bobo's secret number (>2): ");
    int bSecretNum = sc.nextInt();
    sc.nextLine();

    Agent alice = new Agent(aSecretNum);
    Agent bobo = new Agent(bSecretNum);

    alice.performKeyExchange(bobo);

    // pass a message
    System.out.println("Write message: ");
    String msg = sc.nextLine();

    passAStringMessage(alice, bobo, msg);
    passAByteArrayMessage(alice, bobo, msg);

  }
}
