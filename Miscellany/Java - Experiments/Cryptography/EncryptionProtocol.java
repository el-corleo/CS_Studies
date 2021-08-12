public class EncryptionProtocol {

  public final char LOWEST_ASCII_CHAR = 32;   // ' '
  public final char ASCII_RANGE = 126 - 32;   // from ' ' to '~'
  public final int N = 3;                     // a prime number (typically much larger than this)
  public final int BASE = 2;                  // a common base uniform to all using this algorithm


  public int computeKey(int secretNum) { return ((int) (Math.pow(BASE, secretNum)) % N); }


  private char processChar(char c, int offset) {
    char new_c = (char) (c - LOWEST_ASCII_CHAR);
    new_c = (char) ((new_c + offset) % ASCII_RANGE);
    new_c += LOWEST_ASCII_CHAR;

    return new_c;
  }


  public String processMessage(String msg, int combinedKey, boolean encrypt) {
    int offset = (encrypt) ? computeKey(combinedKey) : -computeKey(combinedKey);
    StringBuilder processedMsg = new StringBuilder();

    for (int i = 0; i < msg.length(); i++)
      processedMsg.append(processChar(msg.charAt(i), offset));

    return processedMsg.toString();
  }

}
