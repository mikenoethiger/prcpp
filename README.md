Arbeitsmaterialien für die Studenten des Moduls: `prcpp`
========================================================

Hier finden Sie alle nötigen Daten wie Beispiel-Projekte, Folien,
Arbeitsblätter und Testat-Übungen.

Klonen Sie das Repository innerhalb ihrer Entwicklungs-VM folgendermassen:

~~~
cd
mkdir prcpp && cd prcpp
git clone git@gitlab.fhnw.ch:prcpp/students/workspace.git
cd workspace
git checkout -b private/<my_name>
~~~

Nun haben Sie das Repository ausgecheckt und einen privaten Branch erstellt,
auf welchem Sie ihre Änderungen commiten können. Ersetzten Sie <my_name>
durch ihren Namen: z.B: christian_lang. Sollten Updates auf dem master Branch
publiziert werden, können Sie ihren Branch folgendermassen darauf rebasen:

~~~
git checkout master
git pull
git checkout -
git rebase master
~~~
