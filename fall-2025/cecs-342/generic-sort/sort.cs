using System;
using System.Collections.Generic;
using System.Linq;

class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    // Allows for direct printing of Person objects
    public override string ToString() => $"{Name}, {Age}";
}

class Program
{
    static void Main()
    {
        Console.WriteLine("CECS 342 Assignment 6");
        Console.WriteLine("Name: Carlos Aguilera");
        Console.WriteLine("Algorithm: generic sort, Language: C#\n");

        List<double> numbers = new List<double>
        {
            645.41, 37.59, 76.41, 5.31, -34.23, 1.11,
            1.10, 23.46, 635.47, -876.32, 467.83, 62.25
        };

        List<Person> people = new List<Person>
        {
            new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), new Person("Kassandra", 21),
            new Person("Lawrence", 25), new Person("Cindy", 22), new Person("Cory", 27), new Person("Mac", 19),
            new Person("Romana", 27), new Person("Doretha", 32), new Person("Danna", 20), new Person("Zara", 23),
            new Person("Rosalyn", 26), new Person("Risa", 24), new Person("Benny", 28), new Person("Juan", 33),
            new Person("Natalie", 25)
        };

        // Sort numbers in ascending order
        numbers.Sort();
        Console.WriteLine("Numbers sorted in ascending order:");
        foreach (var n in numbers) {
            Console.WriteLine(n);
        }

        Console.WriteLine();
        // Sort people alphabetically by name
        var peopleByName = people.OrderBy(p => p.Name).ToList();
        Console.WriteLine("People sorted alphabetically by name:");
        foreach (var p in peopleByName) {
            Console.WriteLine(p);
        }

        Console.WriteLine();

        // Sort people by age (descending), then by name
        var peopleByAge = people.OrderByDescending(p => p.Age).ThenBy(p => p.Name).ToList();
        Console.WriteLine("People sorted by age (descending), then by name:");
        foreach (var p in peopleByAge) {
            Console.WriteLine(p);
        }
    }
}
