// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    std::stack<char> st;
    std::string s;
    
    bool ok = true;

    std::getline(std::cin, s);

    if (!std::cin)
    {
        return false;
    }
    
    for (char& a : s)
    {
        char aux;
        if (a == '(' || a == '[' || a == '{')
        {
            st.push(a);
        }
        else if (a == ')' || a == ']' || a == '}')
        {
            if (st.empty()) {
                ok = false;
            }
            else
            {
                aux = st.top();
                if (a == ')' && aux == '(')
                {
                    st.pop();
                }
                else if (a == ']' && aux == '[')
                {
                    st.pop();
                }
                else if (a == '}' && aux == '{')
                {
                    st.pop();
                }
                else {
                    ok = false;
                }
            }
        }
    }

    if (st.size() != 0) {
        ok = false;
    }

    if (ok)
    {
        std::cout << "SI" << '\n';
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

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
