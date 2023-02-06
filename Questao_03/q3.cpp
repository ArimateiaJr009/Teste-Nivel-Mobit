#include <iostream>
#include <fstream>
#include <queue>
#include <pthread.h>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

using namespace std;
queue<string> queue;
pthread_mutex_t mutex;


void *ProducerThread(void *arg) {

    doc.parse<0>(xmlFile.data()); // carregando xml
    rapidxml::xml_node<> *root_node = doc.first_node("root"); //setando no raiz

    //varreando todos os nos da fila
    for (rapidxml::xml_node<> *node = root_node->first_node("payload"); node; node = node->next_sibling("payload"))
    {
        pthread_mutex_lock(&mutex); //bloqueio de recursos compartilhados

        queue.push(node->value()); // inserindo alvo

        pthread_mutex_unlock(&mutex); //desbloqueio de recursos compartilhados
    }
    return NULL;
}

void *ConsumerThread(void *arg) {
    string payload;
    while (true) {
        pthread_mutex_lock(&mutex); //bloqueio de recursos compartilhados

        //varre a fila enquanto não for vazia
        while (!queue.empty()) {
        payload = queue.front(); //carrega a variavel payload
        queue.pop(); //atualiza a fila
        cout << "Payload: " << payload << endl; //apresenta o valor
        pthread_mutex_unlock(&mutex); //libera recursos comparilhados
                              }
                 }
    return NULL;
}

int main()
{

    rapidxml::xml_document<> doc;           // instanciando doc para o objeto rapidxml
    rapidxml::file<> xmlFile("input.xml");  // carregando o arquivo xml


    pthread_t producer, consumer;     //declara as thread

    //inicializa os objetos "thread"
    pthread_mutex_init(&mutex, NULL);


    //cria as novas threads de execução
    pthread_create(&producer, NULL, ProducerThread, NULL);
    pthread_create(&consumer, NULL, ConsumerThread, NULL);

    //finaliza as threads
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    //limpa
    pthread_mutex_destroy(&mutex);
    return 0;
}
