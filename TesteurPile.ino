
// Définition des variables

int ledRouge = 2 ;  // Numéro de la borne alimentant la DEL Rouge

int ledVerte = 3 ;  // Numéro de la borne alimentant la DEL Verte

int niveau ;  // Variable recueillant le niveau lu sur l'entrée A0

float uPile ; // Tension à vide de la pile

float uSeuil ;  // Limite pile usée / pile en bon état


void setup() {

  // put your setup code here, to run once:

  uSeuil = 1.30 ; // On fixe la valeur de la tension de seuil

  // Définition des bornes en sortie (OUTPUT)

  pinMode(ledRouge, OUTPUT);

  pinMode(ledVerte, OUTPUT);

  // On éteint tout

  digitalWrite(ledRouge, 0) ;

  digitalWrite(ledVerte, 0) ;

}


void loop() {

  // put your main code here, to run repeatedly:

  niveau = analogRead(A0) ; // Lecture du signal sur l'entrée A0

  uPile = niveau * 5. / 1023. ; // Calcul de la tension lue aux bornes de la pile

  if (uPile >= uSeuil) { // Comparaison avec la tension définie comme seuil

    digitalWrite(ledVerte, 1) ;  // On allume la DEL verte

    digitalWrite(ledRouge, 0) ;  // On éteint la DEL rouge

  }

  else {

    digitalWrite(ledVerte, 0) ;  // On éteint la DEL verte

    digitalWrite(ledRouge, 1) ;  // On allume la DEL rouge

  }

}
