using HolidaysViewer.Models;

namespace HolidaysViewer.Interfaces;

public interface IHolidaysApiService
{
  Task<List<HolidayModel>> GetHolidays(string countryCode, int year);
}
