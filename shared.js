// ====== GLOBAL CONFIG ======
const API_URL = "______FILL THIS_____________";

// ====== UTILITIES ======
function getStudentOrRedirect() {
  const raw = localStorage.getItem("student");
  if (!raw) {
    window.location.href = "index.html";
    return null;
  }
  try {
    return JSON.parse(raw);
  } catch {
    localStorage.removeItem("student");
    window.location.href = "index.html";
    return null;
  }
}

function getJsonResponse(res) {
  if (!res.ok) {
    throw new Error("Network error: " + res.status);
  }
  return res.json();
}

function getQueryParam(name) {
  const url = new URL(window.location.href);
  return url.searchParams.get(name);
}
