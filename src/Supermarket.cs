using System;
using System.Collections.Generic;

class Item
{
    public string Name { get; set; }
    public double Price { get; set; }

    public Item(string name, double price)
    {
        Name = name;
        Price = price;
    }
}

class GroceryItem : Item
{
    public GroceryItem(string name, double price) : base(name, price) { }
}

class ElectronicItem : Item
{
    public ElectronicItem(string name, double price) : base(name, price) { }
}

class HealthCareItem : Item
{
    public HealthCareItem(string name, double price) : base(name, price) { }
}

class HouseholdItem : Item
{
    public HouseholdItem(string name, double price) : base(name, price) { }
}

class ShoppingCart
{
    public List<Item> Items { get; private set; } = new List<Item>();

    public void AddItem(Item item)
    {
        Items.Add(item);
    }

    public void RemoveItem(Item item)
    {
        Items.Remove(item);
    }

    public double CalculateTotal()
    {
        double total = 0.0;
        foreach (Item item in Items)
        {
            total += item.Price;
        }
        return total;
    }

    public void DisplayCart()
    {
        Console.WriteLine("Shopping Cart:");
        foreach (Item item in Items)
        {
            Console.WriteLine($"{item.Name} - Rs.{item.Price}");
        }
    }
}

class Supermarket
{
    static void Main(string[] args)
    {
        ShoppingCart cart = new ShoppingCart();

        while (true)
        {
            Console.WriteLine("Choose an option:");
            Console.WriteLine("1. Add item to cart");
            Console.WriteLine("2. Remove item from cart");
            Console.WriteLine("3. View cart");
            Console.WriteLine("4. Checkout");
            Console.WriteLine("5. Exit");

            int option = int.Parse(Console.ReadLine());

            switch (option)
            {
                case 1:
                    Console.WriteLine("Enter item name:");
                    string itemName = Console.ReadLine();
                    Console.WriteLine("Enter item price:");
                    double itemPrice = double.Parse(Console.ReadLine());
                    Console.WriteLine("Enter item category (1. Grocery, 2. Electronics, 3. HealthCare, 4. Household):");
                    int categoryChoice = int.Parse(Console.ReadLine());
                    Item newItem;

                    if (categoryChoice == 1)
                    {
                        newItem = new GroceryItem(itemName, itemPrice);
                    }
                    else if (categoryChoice == 2)
                    {
                        newItem = new ElectronicItem(itemName, itemPrice);
                    }
                    else if (categoryChoice == 3)
                    {
                        newItem = new HealthCareItem(itemName, itemPrice);
                    }
                    else if (categoryChoice == 4)
                    {
                        newItem = new HouseholdItem(itemName, itemPrice);
                    }
                    else
                    {
                        Console.WriteLine("Invalid category choice");
                        continue;
                    }

                    cart.AddItem(newItem);
                    Console.WriteLine($"{itemName} has been added to the cart.");
                    break;

                case 2:
                    Console.WriteLine("Enter the name of the item to remove:");
                    string itemToRemove = Console.ReadLine();
                    Item foundItem = cart.Items.Find(item => item.Name.Equals(itemToRemove, StringComparison.OrdinalIgnoreCase));
                    if (foundItem != null)
                    {
                        cart.RemoveItem(foundItem);
                        Console.WriteLine($"{itemToRemove} has been removed from the cart.");
                    }
                    else
                    {
                        Console.WriteLine($"{itemToRemove} not found in the cart.");
                    }
                    break;

                case 3:
                    cart.DisplayCart();
                    break;

                case 4:
                    double total = cart.CalculateTotal();
                    Console.WriteLine($"Total: Rs.{total}");
                    break;

                case 5:
                    Console.WriteLine("Thank you for shopping with us!");
                    Environment.Exit(0);
                    break;

                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
