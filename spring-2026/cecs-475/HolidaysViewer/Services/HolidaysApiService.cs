using HolidaysViewer.Interfaces;
using HolidaysViewer.Models;
using System.Text.Json;

namespace HolidaysViewer.Services;

public class HolidaysApiService : IHolidaysApiService
{
  private static readonly HttpClient client;
  static HolidaysApiService()
  {
    client = new HttpClient()
    {
      BaseAddress = new Uri("https://date.nager.at")
    };
  }

  public async Task<List<HolidayModel>> GetHolidays(string countryCode, int year)
  {
    var response = await client.GetAsync($"/api/v3/PublicHolidays/{year}/{countryCode}");
    var content = await response.Content.ReadAsStringAsync();

    if (!response.IsSuccessStatusCode)
    {
      throw new Exception($"Failed to get holidays for {countryCode} in {year}: {content}");
    }

    var holidays = JsonSerializer.Deserialize<List<HolidayModel>>(content,
      new JsonSerializerOptions
      {
        PropertyNameCaseInsensitive = true,
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase
      }
    );

    if (holidays == null)
    {
      return [];
    }

    return holidays;
  }
}