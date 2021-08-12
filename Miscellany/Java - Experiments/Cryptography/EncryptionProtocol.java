public class EncryptionProtocol {

  public final int ASCII_RANGE = 128;
  public final int BYTE_SIZE = 256;
  public final int N = 23;    // a large public prime (usually much larger than this)
  public final int BASE = 7;  // a common base uniform to all using this algorithm


  public int computeKey(int secretNum) { return ((int) (Math.pow(BASE, secretNum)) % N); }


  private char processChar(char c, int offset) {
    char new_c = (char) ((char) (c + offset) % ASCII_RANGE);

    return new_c;
  }


  public String processMessage(String msg, int combinedKey, boolean encrypt) {
    int offset = (encrypt) ? computeKey(combinedKey) : -computeKey(combinedKey);
    StringBuilder processedMsg = new StringBuilder();

    for (int i = 0; i < msg.length(); i++)
      processedMsg.append(processChar(msg.charAt(i), offset));

    return processedMsg.toString();
  }

  public byte[] processMessage(byte[] msg, int combinedKey, boolean encrypt) {
    int offset = (encrypt) ? computeKey(combinedKey) : -computeKey(combinedKey);
    byte[] processedMsg = new byte[msg.length];

    for (int i = 0; i < msg.length; i++)
      processedMsg[i] = (byte) ((msg[i] + offset) % BYTE_SIZE);

    return processedMsg;
  }

}
