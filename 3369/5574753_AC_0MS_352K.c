#include <stdio.h>
double ans[949][4] = {{0.08,4.10,7.50,8.00},{0.08,4.20,7.50,7.75},{0.08,4.38,6.25,9.00},{0.08,4.45,6.25,8.80},{0.08,4.50,6.20,8.75},{0.08,4.80,6.25,7.95},{0.08,5.00,6.29,7.50},{0.08,5.40,6.25,6.90},{0.08,5.50,6.25,6.76},{0.08,5.92,6.25,6.25},{0.09,3.75,6.00,9.60},{0.09,4.90,6.25,6.40},{0.10,2.85,7.00,10.00},{0.10,3.00,6.55,10.00},{0.10,3.00,7.50,8.48},{0.10,3.10,6.25,10.08},{0.10,3.12,7.50,8.00},{0.10,3.19,6.25,9.60},{0.10,3.20,6.25,9.55},{0.10,3.22,6.00,10.00},{0.10,3.50,5.44,10.00},{0.10,3.60,6.25,7.96},{0.10,3.72,6.25,7.60},{0.10,3.75,5.12,9.75},{0.10,3.75,5.50,8.80},{0.10,3.75,6.00,7.88},{0.10,3.75,6.50,7.20},{0.10,3.96,4.75,10.00},{0.10,4.00,4.50,10.75},{0.10,4.00,4.70,10.00},{0.10,4.00,5.00,9.10},{0.10,4.00,5.14,8.75},{0.10,4.00,5.25,8.50},{0.10,4.00,5.50,8.00},{0.10,4.00,5.80,7.50},{0.10,4.00,6.25,6.90},{0.10,4.25,6.25,6.40},{0.10,4.50,5.00,7.68},{0.10,4.60,5.84,6.25},{0.10,4.78,5.60,6.25},{0.10,4.84,5.00,7.00},{0.10,5.00,5.55,6.00},{0.11,2.85,6.25,9.60},{0.11,3.00,5.70,10.00},{0.11,4.00,4.15,10.00},{0.11,4.00,5.92,6.25},{0.12,2.50,5.84,11.25},{0.12,2.50,6.31,10.00},{0.12,2.50,6.50,9.60},{0.12,2.50,7.25,8.40},{0.12,2.60,6.00,10.00},{0.12,2.90,5.25,10.00},{0.12,3.00,5.00,10.15},{0.12,5.00,5.00,5.06},{0.13,2.35,6.25,9.60},{0.13,2.80,6.25,7.20},{0.13,3.00,5.25,8.00},{0.14,2.40,4.70,12.50},{0.14,2.50,5.50,8.80},{0.14,2.50,6.24,7.50},{0.14,3.00,3.68,12.50},{0.14,3.00,4.00,10.50},{0.14,3.00,5.00,7.40},{0.14,3.60,5.00,5.75},{0.14,3.75,4.60,6.00},{0.15,1.65,8.00,10.00},{0.15,1.75,8.00,9.00},{0.15,1.92,6.25,10.40},{0.15,1.92,7.50,8.25},{0.15,2.00,6.25,9.60},{0.15,2.00,7.25,8.00},{0.15,2.00,7.50,7.72},{0.15,2.04,5.20,12.50},{0.15,2.24,5.25,10.00},{0.15,2.40,4.30,12.50},{0.15,2.40,6.25,7.04},{0.15,2.50,4.00,13.30},{0.15,2.50,4.50,10.40},{0.15,2.50,4.60,10.00},{0.15,2.50,5.60,7.50},{0.15,2.50,5.76,7.25},{0.15,2.50,6.00,6.92},{0.15,2.56,6.25,6.40},{0.15,2.63,5.00,8.00},{0.15,2.75,3.75,12.16},{0.15,2.83,4.00,10.00},{0.15,3.00,5.00,6.52},{0.15,3.17,3.20,12.50},{0.15,3.20,4.80,6.25},{0.15,3.40,3.75,8.00},{0.15,3.40,4.48,6.25},{0.15,3.75,4.00,6.32},{0.16,1.65,7.50,9.50},{0.16,1.70,7.50,9.00},{0.16,1.75,6.25,10.88},{0.16,1.76,6.25,10.75},{0.16,1.78,6.25,10.50},{0.16,1.90,5.20,12.50},{0.16,1.90,5.50,11.25},{0.16,1.95,6.25,8.80},{0.16,2.00,6.25,8.41},{0.16,2.00,6.90,7.50},{0.16,2.14,6.25,7.50},{0.16,2.25,4.26,12.50},{0.16,2.25,6.00,7.25},{0.16,2.30,6.25,6.70},{0.16,2.35,5.50,7.50},{0.16,2.38,4.00,12.50},{0.16,2.50,3.70,13.25},{0.16,2.50,3.75,12.82},{0.16,2.50,3.79,12.50},{0.16,2.50,4.00,11.10},{0.16,2.50,4.22,10.00},{0.16,2.50,4.50,8.95},{0.16,2.50,4.65,8.50},{0.16,2.50,5.00,7.66},{0.16,2.50,5.08,7.50},{0.16,2.50,5.50,6.80},{0.16,2.50,5.94,6.25},{0.16,2.56,5.75,6.25},{0.16,2.85,3.30,12.50},{0.16,2.90,4.90,6.25},{0.16,2.95,4.80,6.25},{0.16,3.00,4.10,7.50},{0.16,3.26,3.75,7.50},{0.16,3.28,4.25,6.25},{0.16,3.47,4.00,6.25},{0.16,3.60,3.85,6.25},{0.16,3.75,4.00,5.65},{0.17,4.00,4.00,4.75},{0.18,1.60,7.50,8.00},{0.18,2.40,4.50,7.50},{0.18,2.50,4.00,8.35},{0.18,2.80,5.00,5.25},{0.18,2.98,4.00,6.25},{0.18,3.75,3.76,5.00},{0.19,1.25,8.32,10.00},{0.19,2.15,4.00,10.00},{0.20,1.25,8.00,9.45},{0.20,1.25,8.36,9.00},{0.20,1.28,8.25,8.75},{0.20,1.38,6.25,10.80},{0.20,1.40,5.64,12.50},{0.20,1.50,5.85,10.00},{0.20,1.50,7.36,7.50},{0.20,1.57,5.50,10.00},{0.20,1.60,6.25,8.05},{0.20,1.62,5.00,11.00},{0.20,1.71,4.40,12.50},{0.20,1.75,4.78,10.00},{0.20,1.80,5.00,8.75},{0.20,1.80,6.25,6.60},{0.20,1.96,5.80,6.25},{0.20,2.00,3.50,14.25},{0.20,2.00,3.75,11.90},{0.20,2.00,4.38,8.75},{0.20,2.00,4.85,7.50},{0.20,2.00,5.00,7.20},{0.20,2.05,5.44,6.25},{0.20,2.24,5.00,6.00},{0.20,2.25,4.80,6.25},{0.20,2.25,5.00,5.96},{0.20,2.34,4.00,7.50},{0.20,2.39,3.75,8.00},{0.20,2.40,3.02,12.50},{0.20,2.50,2.80,13.75},{0.20,2.50,2.94,12.00},{0.20,2.50,3.00,11.40},{0.20,2.50,3.25,9.52},{0.20,2.50,3.88,7.00},{0.20,2.50,4.00,6.70},{0.20,2.50,4.35,6.00},{0.20,2.50,4.50,5.76},{0.20,2.55,5.00,5.00},{0.20,2.64,3.00,10.00},{0.20,2.80,3.70,6.25},{0.20,3.00,3.00,7.75},{0.20,3.00,3.75,5.56},{0.20,3.00,4.10,5.00},{0.20,3.12,3.30,6.25},{0.20,3.48,3.50,5.00},{0.21,1.25,8.00,8.60},{0.21,2.15,3.20,12.50},{0.21,2.50,4.00,6.10},{0.22,1.20,6.25,11.80},{0.22,1.25,6.75,9.60},{0.22,1.36,6.25,9.00},{0.22,1.65,6.25,6.40},{0.22,1.72,6.00,6.25},{0.22,1.75,4.20,10.00},{0.22,2.00,4.84,6.25},{0.22,2.40,2.70,12.50},{0.22,2.40,3.75,6.50},{0.22,2.50,2.50,13.92},{0.22,2.50,3.00,8.80},{0.22,2.50,3.68,6.25},{0.22,2.50,4.00,5.60},{0.23,2.40,2.50,13.50},{0.23,2.50,2.68,10.00},{0.24,1.25,5.00,12.98},{0.24,1.30,6.25,8.20},{0.24,1.32,4.75,12.50},{0.24,1.42,6.25,7.00},{0.24,1.50,5.75,7.00},{0.24,2.10,2.80,12.50},{0.24,2.25,3.68,6.25},{0.24,2.50,2.50,10.48},{0.24,2.50,3.87,5.00},{0.24,2.55,3.20,6.25},{0.25,0.93,8.75,9.60},{0.25,1.00,6.80,11.50},{0.25,1.00,7.00,11.00},{0.25,1.00,7.36,10.25},{0.25,1.00,7.50,10.00},{0.25,1.00,7.75,9.60},{0.25,1.00,8.00,9.25},{0.25,1.00,8.20,9.00},{0.25,1.06,6.25,11.52},{0.25,1.11,6.40,10.00},{0.25,1.12,6.25,10.16},{0.25,1.15,6.08,10.00},{0.25,1.15,6.25,9.60},{0.25,1.20,5.00,12.90},{0.25,1.20,6.25,8.80},{0.25,1.20,6.75,8.00},{0.25,1.20,7.16,7.50},{0.25,1.22,6.00,9.00},{0.25,1.24,5.00,11.80},{0.25,1.25,4.80,12.60},{0.25,1.25,5.08,11.20},{0.25,1.25,5.20,10.72},{0.25,1.25,5.55,9.60},{0.25,1.25,6.40,7.90},{0.25,1.25,6.96,7.20},{0.25,1.28,5.50,9.25},{0.25,1.28,6.25,7.78},{0.25,1.28,6.45,7.50},{0.25,1.30,5.00,10.48},{0.25,1.32,6.25,7.36},{0.25,1.34,4.50,12.00},{0.25,1.35,5.00,9.60},{0.25,1.40,4.66,10.00},{0.25,1.42,4.00,13.50},{0.25,1.48,5.20,7.50},{0.25,1.48,6.08,6.25},{0.25,1.50,4.00,11.50},{0.25,1.50,4.08,11.00},{0.25,1.50,4.75,8.32},{0.25,1.50,6.00,6.20},{0.25,1.60,3.75,11.20},{0.25,1.60,3.95,10.00},{0.25,1.60,4.00,9.75},{0.25,1.60,4.24,8.75},{0.25,1.60,5.00,6.85},{0.25,1.60,5.40,6.25},{0.25,1.66,5.12,6.25},{0.25,1.68,5.00,6.30},{0.25,1.70,3.75,9.60},{0.25,1.70,4.00,8.50},{0.25,1.70,4.32,7.50},{0.25,1.72,3.20,13.75},{0.25,1.75,3.20,13.00},{0.25,1.75,4.00,8.00},{0.25,1.75,4.48,6.75},{0.25,1.76,4.72,6.25},{0.25,1.80,5.00,5.64},{0.25,1.82,3.40,10.00},{0.25,1.83,4.48,6.25},{0.25,1.84,4.00,7.25},{0.25,1.85,2.88,15.00},{0.25,1.90,2.80,15.00},{0.25,1.90,3.24,10.00},{0.25,1.90,5.00,5.20},{0.25,1.92,3.00,11.75},{0.25,1.92,3.05,11.25},{0.25,1.92,3.75,7.40},{0.25,1.92,4.21,6.25},{0.25,1.92,4.50,5.75},{0.25,2.00,2.68,14.50},{0.25,2.00,2.85,12.00},{0.25,2.00,3.00,10.50},{0.25,2.00,3.25,8.80},{0.25,2.00,3.36,8.25},{0.25,2.00,3.70,7.00},{0.25,2.00,4.00,6.25},{0.25,2.00,4.50,5.40},{0.25,2.01,4.80,5.00},{0.25,2.04,2.60,15.00},{0.25,2.05,4.00,6.00},{0.25,2.08,2.80,11.25},{0.25,2.08,3.75,6.40},{0.25,2.18,2.50,13.60},{0.25,2.19,3.20,7.50},{0.25,2.20,2.50,13.20},{0.25,2.24,3.25,7.00},{0.25,2.25,2.40,14.00},{0.25,2.25,2.56,11.50},{0.25,2.25,2.75,9.60},{0.25,2.25,3.00,8.00},{0.25,2.25,4.00,5.20},{0.25,2.32,3.36,6.25},{0.25,2.35,2.50,10.88},{0.25,2.40,2.50,10.30},{0.25,2.40,2.53,10.00},{0.25,2.40,2.90,7.50},{0.25,2.40,3.75,5.12},{0.25,2.40,4.00,4.75},{0.25,2.47,2.50,9.60},{0.25,2.50,2.56,8.85},{0.25,2.50,2.60,8.56},{0.25,2.50,2.76,7.60},{0.25,2.50,2.80,7.40},{0.25,2.50,3.05,6.40},{0.25,2.50,3.10,6.24},{0.25,2.50,3.20,5.95},{0.25,2.50,3.34,5.60},{0.25,2.50,3.60,5.08},{0.25,2.50,3.92,4.60},{0.25,2.50,4.00,4.50},{0.25,2.56,3.02,6.25},{0.25,2.56,3.55,5.00},{0.25,2.65,3.75,4.48},{0.25,2.68,2.88,6.25},{0.25,2.75,2.88,6.00},{0.25,2.75,4.00,4.00},{0.25,2.80,3.00,5.50},{0.25,2.80,3.22,5.00},{0.25,3.00,3.00,5.00},{0.25,3.10,3.50,4.00},{0.25,3.20,3.60,3.75},{0.26,0.96,7.50,10.00},{0.26,1.12,7.50,7.50},{0.26,1.25,6.50,7.20},{0.26,1.50,3.68,12.50},{0.26,1.75,4.48,6.25},{0.26,1.95,3.00,10.00},{0.26,2.08,2.50,13.75},{0.26,2.32,2.50,10.00},{0.27,1.25,5.60,8.00},{0.27,2.00,3.00,8.50},{0.28,1.00,6.25,10.04},{0.28,1.25,5.50,7.60},{0.28,1.40,4.00,10.00},{0.28,1.50,3.36,12.50},{0.28,1.50,4.00,8.50},{0.28,1.60,3.25,11.25},{0.28,2.00,2.50,11.95},{0.28,2.13,2.50,10.00},{0.28,2.50,2.50,7.04},{0.29,1.00,6.25,9.28},{0.29,2.40,3.75,4.00},{0.29,2.50,2.56,6.25},{0.30,0.75,8.84,10.00},{0.30,0.80,7.50,10.75},{0.30,0.85,6.24,12.50},{0.30,0.92,5.60,12.50},{0.30,0.95,6.25,9.60},{0.30,1.00,5.00,12.60},{0.30,1.00,5.65,10.00},{0.30,1.00,7.04,7.50},{0.30,1.10,6.25,7.20},{0.30,1.12,4.35,12.50},{0.30,1.20,4.00,12.50},{0.30,1.20,6.20,6.25},{0.30,1.25,3.84,12.25},{0.30,1.25,4.00,11.10},{0.30,1.25,4.20,10.00},{0.30,1.25,4.50,8.80},{0.30,1.25,5.12,7.25},{0.30,1.25,5.60,6.50},{0.30,1.25,6.00,6.04},{0.30,1.30,4.00,10.00},{0.30,1.44,4.70,6.25},{0.30,1.50,4.00,7.25},{0.30,1.50,5.00,5.44},{0.30,1.60,2.88,12.50},{0.30,1.75,2.48,15.00},{0.30,1.75,2.50,14.56},{0.30,1.75,4.00,5.50},{0.30,1.76,2.50,14.25},{0.30,1.76,2.60,12.50},{0.30,1.80,2.75,10.00},{0.30,1.85,2.50,12.00},{0.30,1.86,4.00,5.00},{0.30,1.90,2.40,12.50},{0.30,1.95,3.20,6.25},{0.30,2.00,2.25,13.00},{0.30,2.00,2.46,10.00},{0.30,2.00,2.50,9.60},{0.30,2.00,2.60,8.75},{0.30,2.00,2.80,7.50},{0.30,2.00,3.65,5.00},{0.30,2.00,3.75,4.84},{0.30,2.00,4.00,4.50},{0.30,2.16,2.50,8.00},{0.30,2.20,2.80,6.25},{0.30,2.30,3.75,4.00},{0.30,2.40,2.50,6.50},{0.30,2.50,3.00,4.64},{0.30,2.50,3.40,4.00},{0.31,1.00,6.00,8.50},{0.31,1.75,2.50,12.80},{0.32,0.85,6.25,10.60},{0.32,1.00,6.25,7.57},{0.32,1.00,6.30,7.50},{0.32,1.20,5.55,6.25},{0.32,1.25,3.60,11.75},{0.32,1.25,3.75,10.64},{0.32,1.25,4.35,8.00},{0.32,1.25,5.00,6.57},{0.32,1.25,5.25,6.20},{0.32,1.35,5.00,5.75},{0.32,1.51,4.00,6.25},{0.32,1.62,2.50,15.00},{0.32,1.65,4.25,5.00},{0.32,1.80,2.50,10.50},{0.32,2.25,2.52,6.25},{0.32,2.50,2.50,5.32},{0.32,2.50,3.10,4.00},{0.34,0.70,8.00,10.00},{0.34,1.45,3.00,10.00},{0.34,2.00,2.40,7.50},{0.34,2.50,2.85,4.00},{0.35,0.80,5.46,12.50},{0.35,0.81,6.25,9.60},{0.35,1.00,4.54,10.00},{0.35,1.00,6.25,6.40},{0.35,1.20,4.80,6.25},{0.35,1.25,3.00,14.72},{0.35,1.25,3.20,12.00},{0.35,1.25,3.50,9.60},{0.35,1.25,3.84,8.00},{0.35,1.50,2.50,13.92},{0.35,1.60,3.28,6.25},{0.35,2.00,2.25,8.00},{0.35,2.00,2.94,5.00},{0.35,2.50,2.74,4.00},{0.35,2.50,3.00,3.60},{0.36,0.75,7.50,8.40},{0.36,1.00,3.75,14.60},{0.36,1.00,3.96,12.50},{0.36,1.00,5.00,7.95},{0.36,1.00,5.50,7.00},{0.36,1.35,2.80,12.50},{0.36,1.90,3.00,5.00},{0.36,2.00,2.46,6.25},{0.37,1.20,3.75,8.00},{0.37,1.56,2.50,10.00},{0.37,2.00,3.25,4.00},{0.38,1.00,4.80,7.50},{0.38,1.25,2.90,12.00},{0.40,0.64,6.25,12.15},{0.40,0.65,6.25,11.68},{0.40,0.65,7.50,9.00},{0.40,0.68,7.50,8.25},{0.40,0.70,5.44,12.50},{0.40,0.70,6.25,9.80},{0.40,0.75,5.00,12.30},{0.40,0.75,6.92,7.50},{0.40,0.80,6.25,7.45},{0.40,0.84,5.75,7.50},{0.40,0.87,6.25,6.40},{0.40,0.90,6.04,6.25},{0.40,0.95,3.75,12.00},{0.40,0.96,4.00,10.00},{0.40,1.00,3.28,15.00},{0.40,1.00,3.50,12.25},{0.40,1.00,3.75,10.30},{0.40,1.00,3.80,10.00},{0.40,1.00,4.00,9.00},{0.40,1.00,4.06,8.75},{0.40,1.00,4.45,7.50},{0.40,1.00,5.00,6.40},{0.40,1.00,5.10,6.25},{0.40,1.00,5.50,5.75},{0.40,1.09,5.00,5.50},{0.40,1.12,3.75,7.75},{0.40,1.15,4.16,6.25},{0.40,1.20,2.82,12.50},{0.40,1.20,3.50,7.50},{0.40,1.25,2.73,12.00},{0.40,1.25,3.00,9.30},{0.40,1.25,3.25,7.84},{0.40,1.25,3.46,7.00},{0.40,1.25,4.00,5.65},{0.40,1.25,4.50,4.92},{0.40,1.30,2.50,14.00},{0.40,1.34,3.40,6.25},{0.40,1.39,2.50,11.00},{0.40,1.40,2.50,10.75},{0.40,1.40,3.22,6.25},{0.40,1.50,2.38,10.00},{0.40,1.50,2.50,8.80},{0.40,1.50,3.45,5.00},{0.40,1.50,3.75,4.52},{0.40,1.51,2.20,12.50},{0.40,1.52,2.50,8.50},{0.40,1.60,2.50,7.50},{0.40,1.60,2.75,6.25},{0.40,1.63,3.75,4.00},{0.40,1.65,2.50,7.00},{0.40,1.68,3.00,5.00},{0.40,1.75,2.50,6.20},{0.40,1.75,2.86,5.00},{0.40,1.78,2.50,6.00},{0.40,1.80,3.50,3.75},{0.40,1.81,2.40,6.25},{0.40,1.90,2.28,6.25},{0.40,1.98,2.00,7.50},{0.40,2.00,2.50,4.90},{0.40,2.04,2.50,4.75},{0.40,2.20,2.50,4.25},{0.40,2.25,2.50,4.12},{0.40,2.30,2.50,4.00},{0.40,2.50,2.50,3.60},{0.40,2.50,2.56,3.50},{0.40,2.50,2.95,3.00},{0.41,1.00,3.75,9.60},{0.42,0.60,7.25,10.00},{0.42,0.64,6.25,10.75},{0.42,0.70,6.25,8.80},{0.42,1.00,4.72,6.25},{0.42,1.36,2.50,10.00},{0.42,2.00,2.00,6.50},{0.42,2.00,2.04,6.25},{0.42,2.40,2.50,3.50},{0.43,1.25,2.50,12.16},{0.43,1.30,3.20,6.25},{0.43,2.10,2.50,4.00},{0.44,1.20,3.75,5.50},{0.44,1.25,2.85,8.00},{0.44,1.25,3.75,5.12},{0.44,1.44,2.50,7.50},{0.45,0.50,8.76,10.00},{0.45,0.60,6.50,10.00},{0.45,0.65,5.12,12.50},{0.45,0.80,6.00,6.25},{0.45,0.85,4.00,10.00},{0.45,0.92,4.80,6.25},{0.45,0.95,3.20,12.50},{0.45,1.00,5.00,5.16},{0.45,1.20,3.00,7.50},{0.45,1.25,4.00,4.56},{0.45,1.50,3.50,4.00},{0.45,2.00,2.50,3.96},{0.46,0.60,7.50,8.00},{0.46,0.64,6.25,8.75},{0.46,1.00,4.00,6.50},{0.46,1.02,4.00,6.25},{0.46,1.20,2.40,12.50},{0.47,0.60,6.25,9.60},{0.47,1.00,3.10,10.00},{0.47,1.40,3.00,5.00},{0.48,0.50,7.50,10.60},{0.48,0.55,6.25,11.20},{0.48,0.62,5.00,12.50},{0.48,0.65,4.70,12.50},{0.48,0.65,5.25,10.00},{0.48,0.80,4.25,8.75},{0.48,0.88,3.75,8.75},{0.48,0.90,5.00,5.50},{0.48,0.94,3.00,12.50},{0.48,1.05,2.50,15.50},{0.48,1.10,2.50,12.75},{0.48,1.18,2.50,10.00},{0.48,1.20,2.50,9.50},{0.48,1.20,3.05,6.25},{0.48,1.25,2.50,8.46},{0.48,1.30,2.10,12.50},{0.48,1.31,2.50,7.50},{0.48,1.42,2.50,6.25},{0.48,1.50,1.81,12.50},{0.48,1.50,2.50,5.60},{0.48,1.70,2.50,4.50},{0.48,1.75,2.50,4.30},{0.48,2.30,2.50,3.00},{0.48,2.50,2.50,2.74},{0.49,0.80,5.20,6.25},{0.49,1.00,3.25,8.00},{0.50,0.50,6.50,12.00},{0.50,0.50,7.20,10.25},{0.50,0.50,8.00,9.00},{0.50,0.60,5.00,12.20},{0.50,0.60,5.20,11.25},{0.50,0.60,5.55,10.00},{0.50,0.60,6.25,8.40},{0.50,0.60,6.50,8.00},{0.50,0.60,6.88,7.50},{0.50,0.63,4.64,12.50},{0.50,0.64,6.25,7.39},{0.50,0.65,5.00,9.84},{0.50,0.68,4.40,11.25},{0.50,0.68,5.60,7.50},{0.50,0.70,4.00,13.00},{0.50,0.70,4.48,10.00},{0.50,0.72,3.75,14.20},{0.50,0.72,3.92,12.50},{0.50,0.75,3.50,15.20},{0.50,0.75,3.92,11.00},{0.50,0.75,4.00,10.50},{0.50,0.75,4.75,7.68},{0.50,0.75,5.80,6.00},{0.50,0.80,3.26,15.00},{0.50,0.80,3.45,12.50},{0.50,0.80,3.50,12.00},{0.50,0.80,3.75,10.10},{0.50,0.80,4.02,8.75},{0.50,0.80,4.40,7.50},{0.50,0.80,4.50,7.25},{0.50,0.80,5.00,6.30},{0.50,0.88,4.36,6.25},{0.50,0.88,4.50,6.00},{0.50,0.90,4.00,6.75},{0.50,0.90,5.00,5.12},{0.50,0.99,4.40,5.00},{0.50,1.00,2.50,16.00},{0.50,1.00,2.56,14.50},{0.50,1.00,2.70,12.00},{0.50,1.00,2.80,10.75},{0.50,1.00,3.00,9.00},{0.50,1.00,3.12,8.25},{0.50,1.00,3.25,7.60},{0.50,1.00,3.40,7.00},{0.50,1.00,3.75,6.00},{0.50,1.00,4.00,5.50},{0.50,1.00,4.50,4.80},{0.50,1.05,2.50,12.96},{0.50,1.08,3.75,5.20},{0.50,1.10,2.40,12.50},{0.50,1.12,2.50,10.30},{0.50,1.12,2.85,7.50},{0.50,1.18,2.25,12.00},{0.50,1.18,2.50,8.80},{0.50,1.20,2.34,10.00},{0.50,1.20,2.50,8.40},{0.50,1.20,3.35,5.00},{0.50,1.20,3.75,4.36},{0.50,1.25,2.00,15.00},{0.50,1.25,2.10,12.32},{0.50,1.25,2.27,9.60},{0.50,1.25,2.40,8.30},{0.50,1.25,2.60,6.96},{0.50,1.25,2.94,5.60},{0.50,1.25,3.20,4.95},{0.50,1.25,3.60,4.28},{0.50,1.27,2.20,10.00},{0.50,1.28,2.00,13.50},{0.50,1.28,2.04,12.50},{0.50,1.28,3.75,3.95},{0.50,1.30,1.92,15.00},{0.50,1.30,2.40,7.50},{0.50,1.30,2.50,6.88},{0.50,1.33,2.56,6.25},{0.50,1.35,2.00,11.00},{0.50,1.40,2.00,9.75},{0.50,1.40,2.76,5.00},{0.50,1.44,1.70,16.25},{0.50,1.44,2.34,6.25},{0.50,1.44,2.50,5.55},{0.50,1.49,3.20,3.75},{0.50,1.50,1.75,12.00},{0.50,1.50,1.76,11.75},{0.50,1.50,2.00,8.00},{0.50,1.50,2.40,5.50},{0.50,1.50,3.00,4.00},{0.50,1.56,2.00,7.25},{0.50,1.56,2.50,4.80},{0.50,1.58,2.40,5.00},{0.50,1.60,1.92,7.50},{0.50,1.60,2.50,4.60},{0.50,1.70,2.00,6.00},{0.50,1.70,2.72,3.75},{0.50,1.75,2.50,4.00},{0.50,1.80,2.50,3.84},{0.50,1.90,2.40,3.75},{0.50,2.00,2.00,4.50},{0.50,2.00,2.25,3.80},{0.50,2.00,2.40,3.50},{0.50,2.00,2.75,3.00},{0.50,2.32,2.50,2.80},{0.50,2.40,2.50,2.70},{0.51,1.00,4.20,5.00},{0.52,0.70,4.25,10.00},{0.52,0.75,5.00,6.60},{0.52,1.00,2.50,13.40},{0.52,1.20,2.00,15.00},{0.52,1.25,2.14,10.00},{0.52,1.25,3.75,3.84},{0.53,0.88,4.00,6.25},{0.53,1.00,2.50,12.40},{0.54,1.00,3.28,6.25},{0.54,1.25,1.84,15.00},{0.54,1.25,2.50,6.24},{0.54,1.60,2.50,4.00},{0.55,0.64,6.20,6.25},{0.55,1.00,2.25,16.00},{0.55,1.00,2.50,10.80},{0.55,1.00,3.00,7.00},{0.55,1.00,3.20,6.25},{0.55,1.20,2.56,6.25},{0.55,1.25,1.78,16.00},{0.56,0.75,3.75,8.80},{0.56,0.90,4.25,5.00},{0.56,0.98,3.75,5.00},{0.56,1.00,2.50,10.15},{0.57,1.44,2.00,6.25},{0.58,0.61,4.00,12.50},{0.58,2.00,2.25,3.00},{0.59,0.64,5.50,6.25},{0.59,0.80,3.50,7.50},{0.59,2.08,2.50,2.50},{0.60,0.60,5.00,7.75},{0.60,0.60,5.96,6.25},{0.60,0.63,5.00,7.00},{0.60,0.64,5.35,6.25},{0.60,0.75,5.00,5.08},{0.60,0.80,2.78,12.50},{0.60,0.80,3.00,10.00},{0.60,0.85,3.52,6.25},{0.60,1.00,2.04,16.25},{0.60,1.00,2.25,11.00},{0.60,1.00,2.32,10.00},{0.60,1.00,2.50,8.20},{0.60,1.00,2.60,7.50},{0.60,1.00,3.00,5.75},{0.60,1.00,3.30,5.00},{0.60,1.00,3.75,4.28},{0.60,1.00,4.00,4.00},{0.60,1.08,2.60,6.25},{0.60,1.20,2.30,6.25},{0.60,1.25,1.75,11.52},{0.60,1.25,1.97,8.00},{0.60,1.25,2.00,7.70},{0.60,1.25,3.00,3.88},{0.60,1.30,1.75,10.00},{0.60,1.42,2.50,4.00},{0.60,1.50,2.50,3.68},{0.60,1.50,3.00,3.00},{0.60,1.52,2.00,5.00},{0.60,1.60,1.69,6.25},{0.60,2.00,2.50,2.55},{0.61,0.70,4.00,7.50},{0.61,0.92,2.50,10.00},{0.62,1.50,2.25,4.00},{0.63,1.25,1.75,9.60},{0.63,1.60,1.60,6.25},{0.64,0.65,3.75,9.00},{0.64,0.67,4.50,6.25},{0.64,0.75,3.82,6.25},{0.64,0.76,3.75,6.25},{0.64,0.95,2.80,6.25},{0.64,1.00,2.00,13.00},{0.64,1.00,2.02,12.50},{0.64,1.00,2.50,6.90},{0.64,1.00,2.63,6.25},{0.64,1.00,3.75,3.85},{0.64,1.10,2.35,6.25},{0.64,1.25,1.75,9.10},{0.64,1.25,2.50,4.39},{0.64,1.25,2.82,3.75},{0.64,1.27,2.00,6.25},{0.64,1.30,1.95,6.25},{0.64,1.44,1.75,6.25},{0.64,1.50,2.00,4.50},{0.64,1.88,2.50,2.50},{0.65,0.96,3.75,4.00},{0.65,1.00,2.50,6.64},{0.65,1.16,2.00,7.50},{0.65,1.20,1.64,12.50},{0.65,1.25,1.80,8.00},{0.65,1.25,2.00,6.24},{0.65,1.30,2.50,4.00},{0.66,1.00,2.50,6.40},{0.67,2.00,2.20,2.50},{0.68,1.00,2.44,6.25},{0.68,1.00,3.00,4.50},{0.69,0.80,2.50,10.50},{0.69,1.25,2.50,3.84},{0.70,0.75,2.50,12.64},{0.70,0.76,2.50,12.00},{0.70,0.78,2.40,12.50},{0.70,0.80,2.50,10.00},{0.70,0.80,3.10,6.25},{0.70,1.00,1.95,10.00},{0.70,1.00,2.00,9.25},{0.70,1.00,2.50,5.60},{0.70,1.00,2.68,5.00},{0.70,1.12,2.50,4.50},{0.70,1.20,2.50,4.00},{0.70,1.25,1.50,11.04},{0.70,1.25,2.38,4.00},{0.70,1.30,1.76,6.25},{0.70,1.75,2.40,2.50},{0.70,2.00,2.08,2.50},{0.72,1.25,2.75,3.20},{0.72,1.50,1.50,6.00},{0.73,1.00,2.24,6.25},{0.74,0.75,4.00,4.50},{0.74,1.00,2.25,6.00},{0.74,1.20,1.80,6.25},{0.75,0.75,4.00,4.40},{0.75,0.78,3.00,6.00},{0.75,0.80,2.31,10.00},{0.75,0.80,2.50,8.10},{0.75,0.80,3.75,4.24},{0.75,0.88,2.25,8.00},{0.75,0.90,2.80,5.00},{0.75,0.94,2.00,9.00},{0.75,1.00,1.75,11.20},{0.75,1.00,1.95,8.00},{0.75,1.00,2.00,7.50},{0.75,1.00,2.32,5.50},{0.75,1.00,3.00,3.80},{0.75,1.14,1.50,12.00},{0.75,1.20,2.40,3.75},{0.75,1.20,2.50,3.56},{0.75,1.25,1.28,16.40},{0.75,1.25,1.40,10.88},{0.75,1.25,1.45,9.60},{0.75,1.25,1.60,7.20},{0.75,1.25,1.68,6.40},{0.75,1.25,1.92,4.90},{0.75,1.25,2.40,3.52},{0.75,1.25,2.60,3.20},{0.75,1.28,1.85,5.00},{0.75,1.29,2.50,3.20},{0.75,1.35,2.00,4.00},{0.75,1.47,1.60,5.00},{0.75,1.50,2.00,3.40},{0.75,1.76,2.00,2.75},{0.76,1.06,2.00,6.25},{0.76,1.10,2.50,4.00},{0.76,1.25,2.50,3.28},{0.77,0.80,2.10,12.50},{0.78,0.80,2.70,6.25},{0.78,1.00,2.00,6.75},{0.79,1.00,2.50,4.40},{0.80,0.80,2.25,8.75},{0.80,0.80,3.00,5.00},{0.80,0.88,2.50,5.50},{0.80,0.90,2.50,5.25},{0.80,1.00,1.50,16.50},{0.80,1.00,1.86,7.50},{0.80,1.00,2.50,4.30},{0.80,1.10,1.44,12.50},{0.80,1.20,1.25,16.25},{0.80,1.20,1.65,6.25},{0.80,1.25,1.25,13.20},{0.80,1.25,1.50,7.10},{0.80,1.25,1.61,6.00},{0.80,1.25,2.00,4.05},{0.80,1.25,2.22,3.50},{0.80,1.25,2.25,3.44},{0.80,1.26,2.50,3.00},{0.80,1.31,2.00,3.75},{0.80,1.36,1.45,6.25},{0.80,1.45,2.50,2.50},{0.80,1.46,1.50,5.00},{0.80,1.50,1.50,4.75},{0.80,1.50,2.40,2.50},{0.80,1.75,2.02,2.50},{0.81,1.10,2.00,5.00},{0.82,1.00,2.20,5.00},{0.84,1.00,1.60,10.00},{0.84,1.00,2.60,3.75},{0.85,0.98,2.50,4.00},{0.85,1.00,1.58,10.00},{0.85,1.00,2.00,5.50},{0.85,1.00,2.56,3.75},{0.85,1.16,1.60,6.25},{0.85,1.20,1.25,12.00},{0.85,1.25,1.75,4.48},{0.87,1.00,1.40,15.00},{0.88,0.96,1.50,12.50},{0.88,1.00,2.50,3.65},{0.88,1.75,1.80,2.50},{0.90,1.00,2.50,3.52},{0.90,1.25,2.00,3.32},{0.92,1.00,1.50,9.00},{0.92,1.00,1.72,6.25},{0.92,1.00,2.50,3.40},{0.94,1.00,1.68,6.25},{0.95,1.20,1.25,8.00},{0.96,1.00,1.25,16.05},{0.96,1.11,1.25,10.00},{0.96,1.20,1.25,7.75},{0.96,1.25,1.25,6.92},{0.96,1.25,1.75,3.60},{1.00,1.00,1.20,16.00},{1.00,1.00,1.24,13.50},{1.00,1.00,1.25,13.00},{1.00,1.00,1.30,11.00},{1.00,1.00,1.40,8.50},{1.00,1.00,1.48,7.25},{1.00,1.00,1.50,7.00},{1.00,1.00,1.60,6.00},{1.00,1.00,1.75,5.00},{1.00,1.00,1.80,4.75},{1.00,1.00,2.00,4.00},{1.00,1.00,2.20,3.50},{1.00,1.00,2.25,3.40},{1.00,1.00,2.50,3.00},{1.00,1.05,1.20,12.50},{1.00,1.05,1.25,10.56},{1.00,1.05,2.50,2.80},{1.00,1.10,1.21,10.00},{1.00,1.12,1.30,7.50},{1.00,1.15,2.48,2.50},{1.00,1.18,2.40,2.50},{1.00,1.20,1.25,6.90},{1.00,1.20,1.30,6.25},{1.00,1.20,1.44,5.00},{1.00,1.20,1.70,3.75},{1.00,1.20,2.00,3.00},{1.00,1.20,2.35,2.50},{1.00,1.25,1.30,5.68},{1.00,1.25,1.41,4.80},{1.00,1.25,1.60,3.85},{1.00,1.25,1.80,3.24},{1.00,1.25,2.02,2.80},{1.00,1.27,1.60,3.75},{1.00,1.28,1.75,3.25},{1.00,1.30,1.50,4.00},{1.00,1.40,1.96,2.50},{1.00,1.44,1.90,2.50},{1.00,1.50,1.50,3.20},{1.00,1.50,1.68,2.75},{1.00,1.50,2.00,2.25},{1.00,1.60,1.70,2.50},{1.00,1.75,1.90,2.00},{1.02,1.12,2.50,2.50},{1.04,1.25,1.40,4.50},{1.06,1.25,2.08,2.50},{1.10,1.50,2.00,2.00},{1.12,1.20,1.25,5.25},{1.12,1.25,1.44,3.75},{1.12,1.50,1.60,2.50},{1.13,1.25,2.00,2.40},{1.14,1.20,2.00,2.50},{1.17,1.25,1.60,3.00},{1.19,1.25,1.50,3.20},{1.20,1.25,1.29,4.00},{1.20,1.25,1.40,3.50},{1.20,1.25,1.50,3.16},{1.20,1.25,1.80,2.50},{1.25,1.25,1.28,3.78},{1.25,1.25,1.92,2.21},{1.25,1.40,1.86,2.00},{1.25,1.60,1.75,1.84},
};
int main()
{
    int i;
    for(i = 0;i < 949; i++) printf("%0.2f %0.2f %0.2f %0.2f\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    return 0;
}
