#include <stdio.h>

// Pertes de contact peau/boitier (Real-world physics)
#define COUPLAGE_THERMIQUE 0.15f 

int main() {
    float temp_air, temp_peau, delta_t_ambiant, delta_t_effectif, puissance_mw;

    printf("=== SIMULATEUR DE RECOLTE THERMOELECTRIQUE (TEG) ===\n");
    printf("Entrez la temperature ambiante (en C) : ");
    scanf("%f", &temp_air);

    // Homeostasie (La peau s'adapte a l'air)
    temp_peau = (0.65 * 37.0) + (0.35 * temp_air);
    if (temp_peau < temp_air) temp_peau = temp_air;

    // Calcul du gradient effectif
    delta_t_ambiant = temp_peau - temp_air;
    delta_t_effectif = delta_t_ambiant * COUPLAGE_THERMIQUE;

    // Loi de Seebeck dynamique
    float tension_volts = 1000.0 * 0.0002 * delta_t_effectif;
    puissance_mw = ((tension_volts * tension_volts) / (4.0 * 3.0)) * 1000.0;

    // Affichage
    printf("\n--- LECTURE DES CAPTEURS ---\n");
    printf("Air ambiant      : %.1f C\n", temp_air);
    printf("Peau (calculee)  : %.1f C\n", temp_peau);
    printf("Delta T effectif : %.2f C\n", delta_t_effectif);
    printf("Puissance Nette  : %.2f mW\n", puissance_mw);

    // Garde-fou energetique
    if (puissance_mw < 15.0) {
        printf("\n[ALERTE] Energie < 15 mW. Activation du secours.\n");
    } else {
        printf("\n[OK] Energie nominale.\n");
    }

    return 0;
}
