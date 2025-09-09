const API_URL = "http://localhost:18080"; // your C++ backend port

// Add patient
document.getElementById("addPatientForm").addEventListener("submit", async (e) => {
    e.preventDefault();
    const name = document.getElementById("name").value;
    const age = parseInt(document.getElementById("age").value);

    const response = await fetch(`${API_URL}/add_patient`, {
        method: "POST",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({name, age})
    });

    const data = await response.text();
    alert(data);

    // Reset form
    document.getElementById("addPatientForm").reset();
});

// Load patient list
document.getElementById("loadPatients").addEventListener("click", async () => {
    const response = await fetch(`${API_URL}/get_patients`);
    const patients = await response.json();

    const list = document.getElementById("patientList");
    list.innerHTML = "";
    patients.forEach((p, i) => {
        const li = document.createElement("li");
        li.textContent = `${i + 1}. ${p.name} - ${p.age} years`;
        list.appendChild(li);
    });
});
