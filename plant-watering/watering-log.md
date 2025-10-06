# 🌱 Plant Watering Log

## Overview

This log tracks soil moisture readings and watering activities for the Arduino plant watering project.
It includes environmental and plant details to help interpret soil moisture data accurately.

---

## 🌿 Plant & Environment Details

| Attribute                   | Description                                                       |
| --------------------------- | ----------------------------------------------------------------- |
| **Plant Type**              | Echeveria (succulent)                                             |
| **Pot Size**                | 20 cm diameter × 10 cm height                                     |
| **Soil Type**               | Well-draining succulent mix (recommended: cactus soil + perlite)  |
| **Drainage Hole**           | Yes (ideal for succulents)                                        |
| **Location**                | Indoor desk, bright indirect light                                |
| **Temperature**             | ~22 °C (cool, stable)                                             |
| **Light Exposure**          | No direct sunlight, bright ambient light from large window        |
| **Ideal Watering Interval** | Every **2–3 weeks**, depending on soil dryness and sensor reading |
| **Target Moisture Range**   | 361–508 (Ideal)                                                   |
| **Watering Amount**         | 100 cc (sufficient for full rehydration to ideal range)           |

---

## 📈 Calibration Reference

| Condition      | Reading Range | Interpretation           |
| -------------- | ------------- | ------------------------ |
| Open Air       | 590+          | Sensor not in soil       |
| Dry Soil       | 509+          | Needs watering           |
| Ideal Moisture | 361–508       | Perfect hydration        |
| Very Wet       | <361          | Overwatered, risk of rot |

---

## 💧 Watering Entries

| Date  | Time  | Reading Before | Reading After | Water Added | Status      | Next Check                      |
| ----- | ----- | -------------- | ------------- | ----------- | ----------- | ------------------------------- |
| 5 Oct | 19:29 | 509            | 361           | 100 cc      | Dry → Ideal | 19–26 Oct *(≈ 2–3 weeks later)* |

---

## 📝 Notes

* Raw readings above **509** indicate dry soil that requires watering.
* Readings between **361–508** indicate ideal soil moisture.
* Readings below **361** indicate overwatering conditions.
* Wait for readings above **509** before watering again.
* At ~22 °C indoors, soil drying takes about **2–3 weeks** between waterings.
* If the Echeveria’s lower leaves start to wrinkle slightly, it’s a good cue that it’s ready for the next watering.