class Item {
  private int weight;
  private int value;

  Item(int weight, int value) {
    this.weight = weight;
    this.value = value;
  }

  public int getValue() {
    return this.value;
  }
  public int getWeight() {
    return this.weight;
  }
}