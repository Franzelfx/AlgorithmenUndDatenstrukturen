/*
 * Programm zur Eingabe und Manipulation von Kalenderdaten
 * @autor FabianFranz
 */

typedef short monat_;
typedef short tag_;
typedef struct {
	tag_ tag;
	monat_ monat;
} datum;

struct datum_ {
	tag_ tag;
	monat_ monat;
} erstes;

int main (){
	datum erste, zweite;
	erste.monat = 1;
	zweite.tag = 12;
	erstes.monat = 12;
}
