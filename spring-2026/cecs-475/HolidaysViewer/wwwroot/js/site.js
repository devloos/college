// Please see documentation at https://learn.microsoft.com/aspnet/core/client-side/bundling-and-minification
// for details on configuring this project to bundle and minify static web assets.

// Write your JavaScript code.

document
  .getElementById("date-nager-form")
  .addEventListener("submit", async function (event) {
    event.preventDefault();
    const countryCode = document.getElementById("txtCountryCode").value;
    const year = document.getElementById("txtYear").value;

    const response = await fetch(
      `https://date.nager.at/api/v3/PublicHolidays/${year}/${countryCode}`
    );

    const data = await response.json();

    const holidays = data.map((holiday) => ({
      date: holiday.date,
      name: holiday.name,
      localName: holiday.localName,
      countryCode: holiday.countryCode,
      global: holiday.global,
    }));

    document.getElementById("holidays-table").innerHTML = holidays
      .map(
        (holiday) => `
      <tr>
        <td>${holiday.date}</td>
        <td>${holiday.name}</td>
        <td>${holiday.localName}</td>
        <td>${holiday.countryCode}</td>
        <td>${holiday.global}</td>
      </tr>
    `
      )
      .join("");
  });
