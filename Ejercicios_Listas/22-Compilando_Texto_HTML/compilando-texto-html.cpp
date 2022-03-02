// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

struct tContador
{
    int p;
    int b;
    int i;
    int q;
};

void inicializa(tContador &cont)
{
    cont.p = cont.b = cont.i = cont.q = 0;
}

bool esAbierto(std::string s)
{
    return s == "<p>" || s == "<b>" || s == "<i>" || s == "<q>";
}

bool esCerrado(std::string s)
{
    return s == "</p>" || s == "</b>" || s == "</i>" || s == "</q>";
}

bool resuelveCaso()
{
    std::stack<std::string> st;
    std::string line;
    std::string a;
    tContador cont;
    inicializa(cont);
    bool ok = true;

    getline(std::cin, line);

    if (!std::cin)
    {
        return false;
    }

    int last = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        std::string aux;
        if (line[i] == '<')
        {
            if (line[i + 1] == '/')
            {
                aux = line.substr(i, 4);
            }
            else
            {
                aux = line.substr(i, 3);
            }

            if (esAbierto(aux))
            {
                st.push(aux);
            }
            else if (esCerrado(aux))
            {
                if (st.empty())
                {
                    ok = false;
                }
                else
                {
                    std::string aux2 = st.top();
                    if (aux == "</p>" && aux2 == "<p>")
                    {
                        st.pop();
                        cont.p++;
                    }
                    else if (aux == "</b>" && aux2 == "<b>")
                    {
                        st.pop();
                        cont.b++;
                    }
                    else if (aux == "</q>" && aux2 == "<q>")
                    {
                        st.pop();
                        cont.q++;
                    }
                    else if (aux == "</i>" && aux2 == "<i>")
                    {
                        st.pop();
                        cont.i++;
                    }
                    else
                    {
                        ok = false;
                    }
                }
            }
        }
    }

    if (st.size() != 0)
    {
        ok = false;
    }

    if (ok)
    {
        std::cout << "SI"
                  << " " << cont.p << " " << cont.b << " " << cont.i << " " << cont.q << '\n';
    }
    else
    {
        std::cout << "NO" << '\n';
    }

    return true;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
