# PanzerRoboter (Embedded C++ Projekt)

Dieses Projekt steuert einen kleinen Roboter-Panzer über die WASD-Tasten.  
Es wurde im Rahmen eines Uni-Projekts auf einem STM32-Board umgesetzt und demonstriert modulare Embedded C++-Programmierung.  
Es zeigt meine Fähigkeiten in Embedded C++, Clean-Code-Prinzipien und modularem Softwaredesign.

---

## Features

- Steuerung des Roboters über Tastatur (WASD)  
- Modulare Struktur mit Klassen:
  - `Motor`
  - `PanzerRoboter`
  - `DigitalAdapter`
  - `AnalogOutAdapter`
- Anpassbare Geschwindigkeit via Tastatur (Pwm)
- Sauber getrennte Hardware-Abstraktion durch Adapter-Pattern
- Dokumentation in UML (docs/uml.pdf)

---

## Dependencies / Uni-Bibliothek

Dieses Projekt nutzt Uni-spezifische Bibliotheken für STM32 (ORB7 Framework):

- `EmbSysLib.h` (für `terminal`, `disp`)
- `Module/Rtos/Rtos.h`
- `ReportHandler.h`
- `config.h` (Pins, LEDs, Buttons)

**Hinweis:** Diese Dateien sind aus lizenzrechtlichen Gründen **nicht im Repository enthalten**.  
Im Ordner `lib/` befinden sich **Dummy-Header**, die nur die Struktur abbilden und die Kompilierbarkeit gewährleisten.  
Die Original-Bibliotheken müssen für die Ausführung auf echter Hardware nachgeladen werden.

---

## Build / Kompilierbarkeit

- Das Projekt ist für STM32 Boards und das ORB7 Framework der Uni konzipiert.  
- Mit den Dummy-Headern in `lib/` kann das Projekt **kompilieren**, ohne dass die Original-Bibliotheken vorhanden sind.  
- Um es auf echter Hardware auszuführen, müssen die Original-Library-Dateien der Uni nachgeladen werden.
