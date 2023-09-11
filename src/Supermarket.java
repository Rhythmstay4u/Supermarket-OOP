import java.util.ArrayList;
import java.util.Scanner;

class Item {
    String name;
    double price;

    public Item (String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}

class GroceryItem extends Item {
    public GroceryItem (String name, double price) {
        super(name, price);
    }
}

class ElectronicItem extends Item {
    public ElectronicItem (String name, double price) {
        super(name, price);
    }
}

class HealthCareItem extends Item {
    public HealthCareItem (String name, double price) {
        super(name, price);
    }
}

class HouseholdItem extends Item {
    public HouseholdItem (String name, double price) {
        super(name, price);
    }
}

class ShoppingCart {
    public ArrayList<Item> items = new ArrayList<>();

    public void addItem(Item item) {
        items.add(item);
    }

    public void removeItem(Item item) {
        items.remove(item);
    }

    public double calculateTotal() {
        double total = 0.0;
        for (Item item : items) {
            total += item.getPrice();
        }
        return total;
    }

    public void displayCart() {
        System.out.println("Shopping Cart:");
        for (Item item : items) {
            System.out.println(item.getName() + " - Rs." + item.getPrice());
        }
    }
}
public class Supermarket {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ShoppingCart cart = new ShoppingCart();

        while (true) {
            System.out.println("Choose an option:");
            System.out.println("1. Add item to cart");
            System.out.println("2. Remove item from cart");
            System.out.println("3. View cart");
            System.out.println("4. Checkout");
            System.out.println("5. Exit");

            int option = input.nextInt();
            input.nextLine();

            switch (option) {
                case 1 -> {
                    System.out.println("Enter item name:");
                    String itemName = input.nextLine();
                    System.out.println("Enter item price:");
                    double itemPrice = input.nextDouble();
                    input.nextLine();
                    System.out.println("Enter item category (1. Grocery, 2. Electronics, 3. HealthCare, 4. Household):");
                    int categoryChoice = input.nextInt();
                    input.nextLine();
                    Item newItem;
                    if (categoryChoice == 1) {
                        newItem = new GroceryItem(itemName, itemPrice);
                    } else if (categoryChoice == 2) {
                        newItem = new ElectronicItem(itemName, itemPrice);
                    } else if (categoryChoice == 3) {
                        newItem = new HealthCareItem(itemName, itemPrice);
                    } else if (categoryChoice == 4) {
                        newItem = new HouseholdItem(itemName, itemPrice);
                    } else {
                        System.out.println("Invalid category choice");
                        continue;
                    }
                    cart.addItem(newItem);
                    System.out.println(itemName + " has been added to the cart.");
                }
                case 2 -> {
                    System.out.println("Enter the name of the item of remove:");
                    String itemToRemove = input.nextLine();
                    for (Item item : cart.items) {
                        if (item.getName().equalsIgnoreCase(itemToRemove)) {
                            cart.removeItem(item);
                            System.out.println(itemToRemove + " has been removed from the cart.");
                            break;
                        }
                    }
                }
                case 3 -> cart.displayCart();
                case 4 -> {
                    double total = cart.calculateTotal();
                    System.out.println("Total: Rs" + total);
                }
                case 5 -> {
                    System.out.println("Thank you for shopping with us!");
                    input.close();
                    System.exit(0);
                }
                default -> System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}