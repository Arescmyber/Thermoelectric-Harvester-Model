# 🔋 Thermoelectric Harvester Model (C)

**Concept :** Calcul dynamique de récolte d'énergie (Thermodynamique).
**Objectif :** Simuler la production d'énergie d'un système thermoélectrique (Effet Seebeck) pour un dispositif embarqué.

**Fonctionnement :**
Le programme lit la température ambiante et calcule la température de surface de la peau (modélisation de l'homéostasie). Il intègre un coefficient de **couplage thermique (15%)** pour simuler les pertes de contact réelles entre la peau et le boîtier (problématique majeure des TEG portables). Le gradient thermique effectif est ensuite converti en milliwatts. Si l'énergie chute sous le seuil critique (15 mW), une bascule automatique de sécurité est activée.
