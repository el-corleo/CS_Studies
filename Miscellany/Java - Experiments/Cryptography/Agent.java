public class Agent {

  private EncryptionProtocol crypter;
  private int privateKey;
  private int publicKey;
  private int othersPublicKey;

  public Agent(int secretNum) {
    privateKey = secretNum;
    crypter = new EncryptionProtocol();
    publicKey = crypter.computeKey(privateKey);
  }

  public void performKeyExchange(Agent b) {
    othersPublicKey = b.getPublicKey();  // get b's public key
    b.setOthersPublicKey(publicKey);     // give b a's public key
  }

  public String encryptMsg(String msg) { return crypter.processMessage(msg, getCombinedKey(), true); }
  public byte[] encryptMsg(byte[] msg) { return crypter.processMessage(msg, getCombinedKey(), true); }

  public String decryptMsg(String msg) { return crypter.processMessage(msg, getCombinedKey(), false); }
  public byte[] decryptMsg(byte[] msg) { return crypter.processMessage(msg, getCombinedKey(), false); }

  public int getPublicKey() { return publicKey; }

  public void setOthersPublicKey(int key) { othersPublicKey = key; }

  private int getCombinedKey() { return crypter.computeKey(privateKey*othersPublicKey); }
}
