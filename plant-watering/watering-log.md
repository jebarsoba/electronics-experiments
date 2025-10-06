# Plant Watering Log

## Overview
This log tracks soil moisture readings and watering activities for the Arduino plant watering project.

### Calibration Reference
- **Open Air**: 590+
- **Dry Soil (needs watering)**: 509+
- **Ideal Soil Moisture**: 361-508
- **Very Wet (overwatered)**: <361

## Watering Entries

| Date | Time | Reading Before | Reading After | Water Added | Status |
|------|------|----------------|---------------|-------------|--------|
| 5 Oct | 19:29 | 509 | 361 | 100 cc | Dry → Ideal |

## Notes
- Raw readings above 509 indicate dry soil requiring watering
- Readings between 361-508 indicate ideal soil moisture
- Readings below 361 indicate overwatered conditions
- The log tracks the sensor reading before and after watering to monitor effectiveness