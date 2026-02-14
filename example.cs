#define M_PI 3.141

//register decorateur pour factory native
@register class MyClass {
  //$ : private (ne fait pas parti du nom et peut etre ecrit n'importe ou avant la parenthese )
  //en jaguar le constructeur est considéré privé
  void $constr() {}
  $ void destr() {} //marche aussi

  //% = protected
  int %protected_value;

  //rien pour public
  int public_value = 10;

  //le decorateur @exposed dans une classe permet d'acceder au membre depuis une string
  @exposed
  int exposed_value;
}

//creer un objet de cette classe
MyClass obj = MyClass();  //appelle le constructeur
obj.public_value = 30;  //modifie le membre
//utiliser la reflexion native (factory + membres exposés)
MyClass obj2 = factory::construct("MyClass");  //fonctionne nativement
//ces deux expressions sont equivalentes
obj.exposed_value = 10;
obj.GetMember("exposed_value") = 10;  //modifie le membre
//pour acceder à sa valeur
sys::log(obj.GetMember("exposed_value")); //affiche 10

//equivalent de typedef struct en C, pas d'equivalent a struct de C++ (a part les classes)
struct my_struct_t{
  int int_val;
}

//gestion de la mémoire
container<int> a = new int(3);  //permet l'ownership clair
//equivalent à : 
container<int> a => 3; //=> opérateur de creation et assignation auto
//acceder à la valeur : 
a.get();  //retourne 3
//pour des objets complexes : 
a->member = 3;  //on permet d'acceder directement via ->