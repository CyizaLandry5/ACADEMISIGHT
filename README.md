# **AcademiSight**

Smart module tracking system for universities

AcademiSight is a lightweight full-stack academic tracking system built to help students, class representatives, and Heads of Departments (HODs) easily track module completion. It solves the common challenge faced by universities where students—especially transferred students, weekend learners, day/evening programs—struggle to know which modules they still need, which they have covered, and which they are exempted from.

The system improves planning, reduces confusion, and ensures no student loses modules during their academic journey.

---

## **Why AcademiSight? (Problem Statement)**

Many universities face the following challenges:

* Students do not know which modules they have already completed.
* Transferred students arrive with different histories, making planning difficult.
* Class representatives struggle to request uncovered modules without accurate records.
* HODs and coordinators manually verify which modules each student still needs.
* Missing or repeated modules cause timetable conflicts and academic delays.

These issues create:

* Missed modules
* Repeated modules
* Poor timetable planning
* Manual administrative work
* Unhappy students

**AcademiSight fixes this by giving every student a clear, personalized module-tracking dashboard backed by a real-time database.**

---

## **Key Features**

### **For Students**

* Track completed, uncovered, and exempted modules
* Clearly see academic progress
* Update status at any time
* Full summary generated automatically
* Straightforward step-by-step interface

### **For Class Reps & HODs**

* Identify uncovered modules quickly
* Improve timetable and delivery planning
* Manage transferred students more easily
* Access structured academic data

### **Technical Features**

* Google Apps Script backend (REST API)
* Google Sheets as a lightweight database
* TailwindCSS front-end
* Pagination for large module lists
* Clean modules-by-status calculation
* Fully mobile responsive
* Easy deployment on any hosting

---

## **System Flow**

1. Student enters registration number, full name, and university code.
<img width="706" height="739" alt="image" src="https://github.com/user-attachments/assets/b30c0dbd-66ec-4dd4-b0dd-0a01ab1038c3" />

2. Student selects their department.
<img width="733" height="466" alt="image" src="https://github.com/user-attachments/assets/9b7b3904-1fe6-464e-a7e3-dcfa3e3db7fb" />

3. Student marks each module as “Completed”, “Not Covered”, or “Exempted.”
<img width="975" height="862" alt="image" src="https://github.com/user-attachments/assets/c18593d9-02e5-4326-b00d-18a17ccb3eba" />

4. Student adds contact information.
<img width="727" height="556" alt="image" src="https://github.com/user-attachments/assets/977b49a3-dc71-405b-ab19-ca34273ed72b" />

5. A full academic summary is generated automatically.
<img width="906" height="767" alt="image" src="https://github.com/user-attachments/assets/9d7d1974-5775-4b6f-a9af-d3c85f4f36ac" />

Backend stores:

* Student record
* Department
* Module statuses
* Contact information

---

## **Tech Stack**

* **Frontend:** HTML, JavaScript, TailwindCSS
* **Backend:** Google Apps Script (custom REST API)
* **Database:** Google Sheets
* **Hosting:** XAMPP / Hostinger / Any static hosting
* **Version Control:** GitHub

---

## **API Endpoints**

| Action               | Purpose                             |
| -------------------- | ----------------------------------- |
| `initStudent`        | Create or retrieve a student record |
| `setDepartment`      | Assign department to student        |
| `getModulesPage`     | Load modules in batches of 5        |
| `saveModuleStatuses` | Save status for student’s modules   |
| `saveContacts`       | Save student’s phone and email      |
| `getStudentSummary`  | Return calculated summary           |

---

## **Summary Metrics Calculation**

* **Total Modules** → number of modules in the department
* **Completed** → modules marked “Completed”
* **Exempted** → modules marked “Exempted”
* **Not Covered** → Total – (Completed + Exempted)

This provides students, class reps, and HODs with an immediate understanding of academic gaps.

---

## **Your Role & Contribution**

I designed and built the entire system end-to-end:

* Full-stack development (frontend logic + backend API + database design)
* UI/UX with TailwindCSS
* Google Apps Script API implementation
* Module pagination logic
* Real-time summary computation
* Integration between frontend and Google Sheet backend

As a class representative, I personally experienced the difficulty students face when modules are not properly tracked—especially transferred students. This motivated me to build a system that solves a real academic problem at scale.

This project shows:

* Problem-solving in the education sector
* Strong full-stack engineering skills
* Leadership and innovation
* REST API design
* Real database integration
* UX design and user-centered thinking

---

## **Educational Impact**

AcademiSight is highly beneficial for universities with:

* Transferred students
* Weekend, evening, or modular programs
* Departments with varying module requirements
* Manual academic tracking processes

It improves clarity, decision-making, and academic planning for all stakeholders.

---

## **Motivation (for applications & recruiters)**

As a class representative, I saw firsthand how students struggled to track which modules they had completed or missed, particularly those who transferred from other institutions. This caused timetable conflicts, unnecessary retakes, and confusion for HODs when planning academic delivery.

AcademiSight was created to solve this real problem. It automates module tracking, provides accurate academic summaries, and assists in timetable planning. This project strengthened my full-stack engineering experience and reflects my passion for building solutions that improve educational management across African universities.

---

## **Open Source & Collaboration**

This project is open-source for educational and research purposes.
**Please credit: MPAYIMANA CYIZA Landry** when using or extending it.

---

## **Author**

**MPAYIMANA CYIZA Landry**
Full-Stack Developer & AI Integrator
Founder of *AcademiSight*
