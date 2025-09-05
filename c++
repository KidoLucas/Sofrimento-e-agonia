// Sofrimento-e-agonia
//Um código 200% amador em C++ de rgp


#include <iostream>
#include <string>

using namespace std;

int magia;
struct Características
{
  string nome;
  int atk, def, mp, hp, inte, at;
};

// Raças
enum Raça
{human, elf, dwarf, alacryan};
int raca[4] = {human, elf, dwarf, alacryan};
string raca_texto[4] = {
    "Humano",
    "Elfo",
    "Anão",
    "Alacryano"};

enum Classe{mage, warrior, healer, sup, archer};
int classe[5]{mage, warrior, healer, sup, archer};

enum Subclasse{sub_mage, sub_warrior, sub_healer, sub_sup, sub_archer};
int subclasse[5]{sub_mage, sub_warrior, sub_healer, sub_sup, sub_archer};
string classe_texto[5] = {
    "Mago",
    "Guerreiro",
    "Curandeiro",
    "Suporte",
    "Arqueiro"
  };

int classe_modificadores[5][6] = {
    {5, 3, 4, 2, 3, 0},
    {4, 5, 4, 2, 1, 0},
    {4, 4, 3, -1, 1, 2},
    {2, 2, 3, 2, 2, 0},
    {1, 2, 2, 1, 1, 0}};

string subclasse_texto[5] = {
    "Mago",
    "Guerreiro",
    "Curandeiro",
    "Suporte",
    "Arqueiro"
  };

int subclasse_modificadores[5][6] = {
    {2, 2, 1, 0, 1, 0},
    {2, 2, 2, 0, 0, 0},
    {0, 2, 1, 1, 0, 0},
    {-1, -1, -1, -1, -0},
    {0, 1, 1, 0, 1, 0}
  };

int main()
{
  // Atributos padrão do anão
  Características anao;
  anao.nome = "Anao";
  anao.atk = 7;
  anao.def = 6;
  anao.mp = 0;
  anao.hp = 10;
  anao.inte = 4;
  anao.at = 0;
  // Atributos padrão do humano
  Características humano;
  humano.nome = "Humano";
  humano.atk = 6;
  humano.def = 5;
  humano.mp = 0;
  humano.hp = 8;
  humano.inte = 5;
  humano.at = 0;

  // Atributos padrão do elfo
  Características elfo;
  elfo.nome = "Elfo";
  elfo.atk = 5;
  elfo.def = 4;
  elfo.mp = 0;
  elfo.hp = 10;
  elfo.inte = 6;
  elfo.at = 0;

  // Atributos padrão do alacryano
  Características alacryano;
  alacryano.nome = "Alacryano";
  alacryano.atk = 7;
  alacryano.def = 6;
  alacryano.mp = 0;
  alacryano.hp = 8;
  alacryano.inte = 5;
  alacryano.at = 0;

  // Definir o nome do personagem
  string player_name;

  cout << "Crie seu personagem.\n";
  cout << "De um nome pro seu personagem!" << endl;
  cin.ignore();
  getline(cin, player_name);
  // Definir se o personagem usará magia ou não
  cout << "Voce gostaria que " << player_name << " use magia?\n(0 -> NAO / 1 -> SIM)\n";
  cin >> magia;
  while (magia < 0 || magia > 1){
    cout << "Escolha um valor valido. (0 -> Sem magia / 1 -> Com magia)" << endl;
    cin >> magia;
  }
  if (magia == 1){
    cout << player_name << " possui magia!" << endl;
    anao.mp = 5;
    humano.mp = 5;
    alacryano.mp = 5;
    elfo.mp = 5;
  }
  else{
    cout << player_name << " nao possui magia" << endl;
  }
  // Definir a raça, classe e subclasse do personagem
  int raca_escolhida, classe_escolhida, subclasse_escolhida;
  cout << "Escolha a raça do seu personagem\n (0 -> Humano / 1 -> Elfo / 2 -> Anao / 3 -> Alacryano)\n";
  cin >> raca_escolhida;
  while (raca_escolhida < 0 || raca_escolhida > 3){
    cout << "Escolha uma raca valida.\n (0 -> Humano / 1 -> Elfo / 2 -> Anao / 3 -> Alacryano)\n";
    cin >> raca_escolhida;
  }
  switch (raca_escolhida){
  case human:
    cout << "Voce escolheu a raca Humano\n";
    break;

  case elf:
    cout << "Voce escolheu a raca Elfo\n";
    break;

  case dwarf:
    cout << "Voce escolheu a raca Anao\n";
    break;

  case alacryan:
    cout << "Voce escolheu a raca Alacryano\n";
    break;

  default:
    break;
  }

  cout << "Escolha a classe do seu personagem:\n (0 -> Mago / 1 -> Guerreiro / 2 -> Curandeiro / 3 -> Suporte / 4 -> Arqueiro)\n" << endl;
  cin >> classe_escolhida;
  while (classe_escolhida < 0 || classe_escolhida > 4){
    cout << "Escolha uma classe valida.\n (0 -> Mago / 1 -> Guerreiro / 2 -> Curandeiro / 3 -> Suporte / 4 -> Arqueiro)\n" << endl;
    cin >> classe_escolhida;
  }
  switch (classe_escolhida){
  case mage:
    cout << "Voce escolheu a classe 'mago'!\n";
    break;

  case warrior:
    cout << "Voce escolheu a classe 'guerreiro'!\n";
    break;

  case healer:
    cout << "Voce escolheu a casse 'curandeiro'!\n";
    break;

  case sup:
    cout << "Voce escolheu a classe 'suporte'!\n";
    break;

  case archer:
    cout << "Você escolheu  a classe 'arqueiro'!\n";
    break;

  default:
    break;
  }
  if(classe_escolhida == healer){
    cout << "Essa classe possui a subclasse 'curandeiro' predefinida!" << endl;
    subclasse_escolhida = sub_healer;
  }else{
    cout << "Escolha a subclasse do seu personagem:\n(0 -> Mago / 1 -> Guerreiro / 2 -> Curandeiro / 3 -> Suporte / 4 -> Arqueiro)\n";
  cin >> subclasse_escolhida;
  while (subclasse_escolhida < 0 || subclasse_escolhida > 4){
    cout << "Escolha uma subclasse valida.\n (0 -> Mago / 1 -> Guerreiro / 2 -> Curandeiro / 3 -> Suporte / 4 -> Arqueiro)\n";
    cin >> subclasse_escolhida;
  }
  switch (subclasse_escolhida){
  case sub_mage:
    cout << "Voce escolheu a subclasse 'mago'!\n";
    break;

  case sub_warrior:
    cout << "Voce escolheu a subclasse 'guerreiro'!\n";
    break;

  case sub_healer:
    cout << "Essa subclaase é exclusiva da classe 'curandeiro'! \n Escolha outra subclasse!\n";
    cin >> subclasse_escolhida;
    break;

  case sub_sup:
    cout << "Voce escolheu a classe 'suporte'!\n";
    break;

  case sub_archer:
    cout << "Voce escolheu a classe 'arqueiro'!\n";
    break;

  default:
    break;
  }
}
  cout << "Como todo RPG, voce tem pontos de atributo para distribuir." << endl;
  cout << "Voce possui 5 pontos de atributo para distribuir entre Ataque, Defesa, Mana, Vida e Inteligencia." << endl;
  cout << "\nCada ponto de atributo aumenta o valor base do atributo em 1." << endl;
  cout << "Escolha bem onde vai por seus pontos.\n" << endl;

  int pontos = 5;
  while (pontos > 0){
    int escolha_atributo;
    enum Atributos {atk, def, mp, hp, inte};

    cout << "Voce possui " << pontos << " pontos de atributo para distribuir." << endl;
    cout << "Escolha um atributo para aumentar:\n (0 -> Ataque / 1 -> Defesa / 2 -> Mana / 3 -> Vida / 4 -> Inteligencia)\n";
    cin >> escolha_atributo;
    while (escolha_atributo < 0 || escolha_atributo > 4){
      cout << "Escolha um atributo valido.\n (0 -> Ataque / 1 -> Defesa / 2 -> Mana / 3 -> Vida / 4 -> Inteligencia)\n";
      cin >> escolha_atributo;
    }
    switch (escolha_atributo){
    case atk:
      if (raca_escolhida == human){
        humano.atk += 1;
        pontos -= 1;
        cout << "Ataque base aumentado para " << humano.atk << endl;
      }
      else if (raca_escolhida == elf){
        elfo.atk += 1;
        pontos -= 1;
        cout << "Ataque base aumentado para " << elfo.atk << endl;
      }
      else if (raca_escolhida == dwarf){
        anao.atk += 1;
        pontos -= 1;
        cout << "Ataque base aumentado para " << anao.atk << endl;
      }
      else if (raca_escolhida == alacryan){
        alacryano.atk += 1;
        pontos -= 1;
        cout << "Ataque base aumentado para " << alacryano.atk << endl;
      }
      break;

    case def:
      if (raca_escolhida == human){
        humano.def += 1;
        pontos -= 1;
        cout << "Defesa base aumentada para " << humano.def << endl;
      }
      else if (raca_escolhida == elf){
        elfo.def += 1;
        pontos -= 1;
        cout << "Defesa base aumentada para " << elfo.def << endl;
      }
      else if (raca_escolhida == dwarf){
        anao.def += 1;
        pontos -= 1;
        cout << "Defesa base aumentada para " << anao.def << endl;
      }
      else if (raca_escolhida == alacryan){
        alacryano.def += 1;
        pontos -= 1;
        cout << "Defesa base aumentada para " << alacryano.def << endl;
      }
      break;

    case mp:
      if (raca_escolhida == human){
        humano.mp += 1;
        pontos -= 1;
        cout << "Mana base aumentada para " << humano.mp << endl;
      }
      else if (raca_escolhida == elf){
        elfo.mp += 1;
        pontos -= 1;
        cout << "Mana base aumentada para " << elfo.mp << endl;
      }
      else if (raca_escolhida == dwarf){
        anao.mp += 1;
        pontos -= 1;
        cout << "Mana base aumentada para " << anao.mp << endl;
      }
      else if (raca_escolhida == alacryan){
        alacryano.mp += 1;
        pontos -= 1;
        cout << "Mana base aumentada para " << alacryano.mp << endl;
      }
      break;

    case hp:
      if (raca_escolhida == human){
        humano.hp += 1;
        pontos -= 1;
        cout << "Vida base aumentada para " << humano.hp << endl;
      }
      else if (raca_escolhida == elf){
        elfo.hp += 1;
        pontos -= 1;
        cout << "Vida base aumentada para " << elfo.hp << endl;
      }
      else if (raca_escolhida == dwarf){
        anao.hp += 1;
        pontos -= 1;
        cout << "Vida base aumentada para " << anao.hp << endl;
      }
      else if (raca_escolhida == alacryan){
        alacryano.hp += 1;
        pontos -= 1;
        cout << "Vida base aumentada para " << alacryano.hp << endl;
      }
      break;

    case inte:
      if (raca_escolhida == human){
        humano.inte += 1;
        pontos -= 1;
        cout << "Inteligencia base aumentada para " << humano.inte << endl;
      }
      else if (raca_escolhida == elf){
        elfo.inte += 1;
        pontos -= 1;
        cout << "Inteligencia base aumentada para " << elfo.inte << endl;
      }
      else if (raca_escolhida == dwarf){
        anao.inte += 1;
        pontos -= 1;
        cout << "Inteligencia base aumentada para " << anao.inte << endl;
      }
      else if (raca_escolhida == alacryan){
        alacryano.inte += 1;
        pontos -= 1;
        cout << "Inteligencia base aumentada para " << alacryano.inte << endl;
      }
      break;
    }
  cout << "Seu personagem foi criado com sucesso!\n";
  cout << "Nome: " << player_name << endl;
  cout << "Raca: " << raca_texto[raca_escolhida] << endl;
  cout << "Classe: " << classe_texto[classe_escolhida] << endl;
  if (classe_escolhida != healer){
    cout << "Subclasse: " << subclasse_texto[subclasse_escolhida] << endl;
  }else{
    cout << "Subclasse: Nenhuma (Curandeiro não possui subclasse)" << endl;
  }
    cout << "\n" << endl;
    cout << "Atributos finais: " << endl;
    if (raca_escolhida == human){
      cout << "Ataque: " << humano.atk + classe_modificadores[classe_escolhida][0] + subclasse_modificadores[subclasse_escolhida][0] << endl;
      cout << "Defesa: " << humano.def + classe_modificadores[classe_escolhida][1] + subclasse_modificadores[subclasse_escolhida][1] << endl;
      cout << "Mana: " << humano.mp + classe_modificadores[classe_escolhida][2] + subclasse_modificadores[subclasse_escolhida][2] << endl;
      cout << "Vida: " << humano.hp + classe_modificadores[classe_escolhida][3] + subclasse_modificadores[subclasse_escolhida][3] << endl;
      cout << "Inteligência: " << humano.inte + classe_modificadores[classe_escolhida][4] + subclasse_modificadores[subclasse_escolhida][4] << endl;
      cout << "Aether: " << humano.at << endl;
    }
    else if (raca_escolhida == elf){
      cout << "Ataque: " << elfo.atk + classe_modificadores[classe_escolhida][0] + subclasse_modificadores[subclasse_escolhida][0] << endl;
      cout << "Defesa: " << elfo.def + classe_modificadores[classe_escolhida][1] + subclasse_modificadores[subclasse_escolhida][1] << endl;
      cout << "Mana: " << elfo.mp + classe_modificadores[classe_escolhida][2] + subclasse_modificadores[subclasse_escolhida][2] << endl;
      cout << "Vida: " << elfo.hp + classe_modificadores[classe_escolhida][3] + subclasse_modificadores[subclasse_escolhida][3] << endl;
      cout << "Inteligência: " << elfo.inte + classe_modificadores[classe_escolhida][4] + subclasse_modificadores[subclasse_escolhida][4] << endl;
      cout << "Aether: " << elfo.at << endl;
    }
    else if (raca_escolhida == dwarf){
      cout << "Ataque: " << anao.atk + classe_modificadores[classe_escolhida][0] + subclasse_modificadores[subclasse_escolhida][0] << endl;
      cout << "Defesa: " << anao.def + classe_modificadores[classe_escolhida][1] + subclasse_modificadores[subclasse_escolhida][1] << endl;
      cout << "Mana: " << anao.mp + classe_modificadores[classe_escolhida][2] + subclasse_modificadores[subclasse_escolhida][2] << endl;
      cout << "Vida: " << anao.hp + classe_modificadores[classe_escolhida][3] + subclasse_modificadores[subclasse_escolhida][3] << endl;
      cout << "Inteligência: " << anao.inte + classe_modificadores[classe_escolhida][4] + subclasse_modificadores[subclasse_escolhida][4] << endl;
      cout << "Aether: " << anao.at << endl;
    }
    else if (raca_escolhida == alacryan){
      cout << "Ataque: " << alacryano.atk + classe_modificadores[classe_escolhida][0] + subclasse_modificadores[subclasse_escolhida][0] << endl;
      cout << "Defesa: " << alacryano.def + classe_modificadores[classe_escolhida][1] + subclasse_modificadores[subclasse_escolhida][1] << endl;
      cout << "Mana: " << alacryano.mp + classe_modificadores[classe_escolhida][2] + subclasse_modificadores[subclasse_escolhida][2] << endl;
      cout << "Vida: " << alacryano.hp + classe_modificadores[classe_escolhida][3] + subclasse_modificadores[subclasse_escolhida][3] << endl;
      cout << "Inteligência: " << alacryano.inte + classe_modificadores[classe_escolhida][4] + subclasse_modificadores[subclasse_escolhida][4] << endl;
      cout << "Aether: " << alacryano.at << endl;
    }
  }
 return 0;
}
