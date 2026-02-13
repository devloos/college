using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;

namespace Stock
{
  public class StockBroker
  {
    public string BrokerName { get; set; }
    // The broker holds a list of Stocks (though not strictly needed in this

    public List<Stock> stocks = new List<Stock>();
    // We'll write to "Lab1_output.txt" in the same folder as the .exe
    readonly string destPath =
      System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Lab1_Output.txt");
    // We’ll print this header in both console & file
    public string titles =
      "Broker".PadRight(10) +
      "Stock".PadRight(15) +
      "Value".PadRight(10) +
      "Changes".PadRight(10) +
      "Date and Time";

    public static bool printedHeaderToConsole = false;
    public StockBroker(string brokerName)
    {
      BrokerName = brokerName;
      // Print the header to console
      if (!StockBroker.printedHeaderToConsole)
      {
        Console.WriteLine(titles);
        StockBroker.printedHeaderToConsole = true;
      }

      // Overwrite (false) the file with this same header once
      using (StreamWriter outputFile = new StreamWriter(destPath, false))
      {
        outputFile.WriteLine(titles);
      }
    }
    public void AddStock(Stock stock)
    {
      stocks.Add(stock);
      // Subscribe to the stock’s event using our event handler
      stock.StockEvent += EventHandler;
    }
    private void EventHandler(object sender, StockNotification e)
    {
      if (sender is not null)
        // The second parameter needs to be cast to StockNotification
        Helper(sender, e);
    }

    public void Helper(object sender, StockNotification e)
    {
      // We could cast the sender back to Stock if we needed more info
      Stock newStock = (Stock)sender;
      // Construct the output line
      string message =
        $"{BrokerName.PadRight(10)}" +
        $"{e.StockName.PadRight(15)}" +
        $"{e.CurrentValue.ToString().PadRight(10)}" +
        $"{e.NumChanges.ToString().PadRight(10)}" +
        $"{DateTime.Now}";

      try
      {
        // Append this line to the output file
        using (StreamWriter outputFile = new StreamWriter(destPath, true))
        {
          outputFile.WriteLine(message);
        }
        // Also write to console
        Console.WriteLine(message);
      }
      catch (IOException ex)
      {
        Console.WriteLine(ex.Message);
      }
    }
  }
}