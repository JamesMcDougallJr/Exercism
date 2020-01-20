import java.util.*;
import java.util.ArrayList;

class Knapsack {

  Knapsack() {

  }
  
  int maximumValue(int weight, ArrayList<Item> items) {

		if(items.size() < 1) return 0;
	  Item[][] solution = new Item[items.size()][items.size()-1];
	  for(int i = 0; i < solution.length; i++) {
		  for(int j = 0; j < solution[i].length; j++) {
				if(j > i) {
					solution[i][j] = new Item(0,0);
				} else if(i > 0) {
					int newValue = items.get(i).getValue() + solution[i-1][j].getValue();
					int newWeight = items.get(i).getWeight() + solution[i-1][j].getWeight();
					solution[i][j] = new Item(newValue, newWeight);
				} else {
					solution[i][j] = items.get(i);
				}
		  }
	  }
	
		int maximumVal = -1;
		System.out.println("Max weight: " + weight);
		for(int j = 0; j < solution[solution.length-1].length; j++) {
			int itemVal = solution[solution.length-1][j].getValue();
			int itemWeight = solution[solution.length-1][j].getWeight();
			System.out.println("Value: " + solution[solution.length-1][j].getValue() + "\tWeight: " + solution[solution.length-1][j].getWeight());
			if (itemWeight <= weight && itemVal > maximumVal) {
				maximumVal = itemVal;
			}
		}
		return maximumVal;
  }

}