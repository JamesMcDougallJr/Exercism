import java.util.*;
import java.util.ArrayList;

class Knapsack {
	int maxWeight;

	Knapsack() {

	}

	int maximumValue(int weight, ArrayList<Item> items) {
		this.maxWeight = weight;
		if (items.size() < 1)
			return 0;
		Item[][] solution = new Item[items.size()][weight + 1];
		for (int i = 0; i < solution.length; i++) {
			for (int w = 0; w <= weight; w++) {
				if (i == 0 && items.get(i).getWeight() < weight) {
					solution[i][w] = items.get(i);
				} else if (i == 0) {
					solution[i][w] = new Item(0, 0);
				} else {
					Item currentItem = items.get(i);
					// the more general case
					if (currentItem.getWeight() > w) {
						solution[i][w] = solution[i - 1][w];
					} else {
						Item notSelected = solution[i - 1][w];
						int currentItemWeight = currentItem.getWeight();
						int currentItemValue = currentItem.getValue();
						Item otherItem = solution[i - 1][w - currentItemWeight];
						Item newItem = new Item(currentItemWeight + otherItem.getWeight(), currentItemValue + otherItem.getValue());
						Item[] items2 = { notSelected, newItem };
						solution[i][w] = getMaxValidItem(items2);
					}
				}
			}
		}
		System.out.println("---------------Printing Matrix-------------");
		for (

				int i = 0; i < solution.length; i++) {
			for (int j = 0; j < solution[i].length; j++) {
				System.out.print("| (" + solution[i][j].getWeight() + "," + solution[i][j].getValue() + ") ");
			}
			System.out.println();
		}
		return solution[items.size() - 1][weight].getValue();
	}

	private Item getMaxValidItem(Item[] items) {
		Item maxItem = new Item(0, 0);
		for (Item item : items) {
			if (item.getValue() > maxItem.getValue()) {
				maxItem = item;
			}
		}
		return maxItem;
	}
}