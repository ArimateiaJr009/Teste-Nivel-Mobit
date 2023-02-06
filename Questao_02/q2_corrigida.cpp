#include <iostream>
#include <vector>
#include <thread>
//incluindo bibliotecas para correção
#include <mutex>   //inserido arquivo para fazer o processo de threads
#include <syslog.h> //inserido a biblioteca para escrita no syslog


/*O problema inicialmente estava na falta de consistência na programação paralela. Existem algumas forma de resolver tal incosistência, por exemplo, a
utilização de semaforos ou a que iremos utilizar aqui com a utilização  mutex */


std::mutex p_mutex;  //instanciando o objeto

static const int THREAD_COUNT = 10;

static void print_log(int id)
{
    // gerenciando (bloqueando) o uso do recurso compartilhado
    p_mutex.lock();

    //abrindo a conexão com o sistema de logs
    openlog("q_2", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    // logando a mensagem,com pedido na questão
    syslog(LOG_NOTICE, "Iniciando bloco %d", id);
    syslog(LOG_NOTICE, "Hello world from thread %d", id);
    syslog(LOG_NOTICE, "Fim do bloco %d", id);
    syslog(LOG_NOTICE, "--------------------");

    // Fechando a conexão com o sistem de logs
    closelog();

    // liberando o mutex
    p_mutex.unlock();
}


int main()
{
    std::vector<std::thread> v;

    for (size_t i = 0; i < THREAD_COUNT; i++)
    {
        v.emplace_back(print_log, i);
    }

    for (auto &t : v)
    {
        t.join();
    }

    return 0;
}
