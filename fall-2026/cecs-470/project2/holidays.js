document.getElementById("submit-btn").addEventListener("click", () => {
  const countryCode = document.getElementById("country-code-input").value;
  const year = document.getElementById("year-input").value;
  const requestString = `https://date.nager.at/api/v3/PublicHolidays/${year}/${countryCode}`;

  const tableBody = document.getElementById("table-body");
  tableBody.innerHTML = "";

  fetch(requestString, {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
    },
  })
    .then((response) => {
      if (!response.ok) {
        throw new Error(`Request failed with status ${response.status}`);
      }
      return response.json();
    })
    .then((holidays) => {
      for (const element of holidays) {
        const row = tableBody.insertRow();

        const dateCell = row.insertCell();
        dateCell.textContent = element.date;

        const localNameCell = row.insertCell();
        localNameCell.textContent = element.localName;

        const nameCell = row.insertCell();
        nameCell.textContent = element.name;
      }
    })
    .catch((error) => {
      const row = tableBody.insertRow();
      const cell = row.insertCell();
      cell.colSpan = 3;
      cell.textContent = `No holidays found. ${error.message}`;
    });
});
