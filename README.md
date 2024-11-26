1. Introdução: Descrição do Projeto
Este projeto consiste em um sistema de Histórico de Navegação implementado em linguagem C, inspirado em navegadores de internet. O objetivo é simular a navegação de um usuário, permitindo que ele visite páginas, volte para páginas anteriores, avance para páginas que estavam no histórico, e exiba a página atual. Além disso, o sistema é capaz de salvar o histórico em um arquivo e carregá-lo quando o programa for reiniciado, garantindo que o estado do histórico seja preservado entre as sessões.

A principal estrutura de dados utilizada é uma lista estática que armazena os endereços das páginas visitadas, permitindo um controle simples e eficiente do histórico de navegação. O sistema foi projetado para ser simples, mas funcional, com o objetivo de demonstrar o uso de estruturas de dados e manipulação de arquivos em C.

2. Documentação das Funcionalidades

O que o sistema faz?
O sistema implementa um "navegador" simplificado com as seguintes funcionalidades:

Visitar uma Página: Permite ao usuário adicionar um novo URL ao histórico.
Voltar: Permite ao usuário voltar para a página anterior no histórico.
Avançar: Permite ao usuário avançar para a próxima página no histórico.
Mostrar Página Atual: Exibe o URL da página que está sendo visualizada no momento.
Salvar e Carregar o Histórico: O histórico de navegação é salvo em um arquivo de texto e pode ser carregado automaticamente quando o programa é reiniciado, permitindo que o usuário retome sua navegação de onde parou.
Menu de Opções: O sistema apresenta um menu interativo para o usuário escolher a operação desejada. O menu possui as seguintes opções:

Visitar Página: O usuário pode inserir o URL de uma página, que será adicionada ao histórico.
Voltar: O usuário pode voltar para a página anterior no histórico.
Avançar: O usuário pode avançar para a próxima página visitada.
Mostrar Página Atual: Exibe a página atual, ou uma mensagem se nenhuma página tiver sido visitada.
Sair: Ao escolher essa opção, o sistema salva o histórico em um arquivo e o programa é encerrado.

De que forma? Qual função é utilizada para cada funcionalidade?

1. Visitar Página
Função: visitPage()
Descrição: Quando o usuário escolhe visitar uma nova página, a função visitPage() é chamada. Ela adiciona o novo URL ao histórico e atualiza o índice current e o total de páginas no histórico.
Operação de Arquivo: Não há operação de arquivo nesta função, pois estamos apenas modificando o estado do programa na memória.
2. Voltar
Função: goBack()
Descrição: Esta função permite ao usuário voltar para a página anterior. O índice current é decrementado, e o sistema reflete a navegação para trás.
Operação de Arquivo: Não há operação de arquivo, apenas a manipulação do estado na memória.
3. Avançar
Função: goForward()
Descrição: A função goForward() permite ao usuário avançar para a próxima página, incrementando o índice current. Se não houver páginas para avançar, uma mensagem é exibida.
Operação de Arquivo: Não há operação de arquivo nesta função, apenas manipulação da estrutura de dados em memória.
4. Mostrar Página Atual
Função: displayCurrentPage()
Descrição: A função displayCurrentPage() exibe o URL da página atual. Se o histórico estiver vazio ou se o usuário ainda não tiver visitado nenhuma página, a função exibe uma mensagem de aviso.
Operação de Arquivo: Não há operação de arquivo, apenas a leitura do estado da memória.
5. Salvar o Histórico
Função: saveHistory()
Descrição: Quando o usuário opta por sair do sistema, a função saveHistory() é chamada. Ela grava o estado atual do histórico em um arquivo de texto chamado historico.txt. Os dados gravados incluem o índice da página atual (current), o total de páginas no histórico (total), e as URLs das páginas visitadas.
Operação de Arquivo: Esta função salva os dados no arquivo. Ao ser chamada, o histórico é armazenado permanentemente para futuras execuções.
6. Carregar o Histórico
Função: loadHistory()
Descrição: Quando o programa é iniciado, a função loadHistory() tenta abrir o arquivo historico.txt e carregar os dados salvos. O histórico é restaurado a partir do arquivo, recuperando o índice da página atual, o total de páginas visitadas e as URLs armazenadas.
Operação de Arquivo: Esta função lê os dados do arquivo, garantindo que o histórico seja restaurado após o fechamento do programa.
De que forma as funcionalidades interagem com o arquivo?
Salvar: As funções saveHistory() e loadHistory() são responsáveis pela persistência dos dados. O arquivo historico.txt armazena o histórico de navegação entre as execuções do programa, permitindo que o usuário retome sua navegação a partir do ponto onde parou.
Carregar: Na inicialização do programa, a função loadHistory() verifica se o arquivo de histórico existe. Caso contrário, o histórico começa vazio. Quando o usuário opta por sair, o estado atual do histórico é salvo no arquivo para ser recuperado posteriormente.

3. Conclusão: Considerações Finais e Melhorias Futuras para o Projeto
Considerações Finais
O sistema de Histórico de Navegação desenvolvido foi uma implementação simples, mas eficaz, utilizando conceitos fundamentais de estruturas de dados e manipulação de arquivos.
Ele consegue simular de forma prática a navegação de um navegador, com funcionalidades como "voltar", "avançar", e "visitar uma nova página".
Além disso, a persistência dos dados garante que o usuário possa continuar de onde parou, mesmo após fechar o programa.

A solução foi implementada com uma estrutura de dados simples (array de URLs) e manipulação básica de arquivos, mas já oferece uma boa demonstração de como é possível aplicar esses conceitos em um sistema real.

Melhorias Futuras
Embora o sistema já atenda aos requisitos básicos, há várias melhorias que podem ser feitas para torná-lo mais robusto e funcional:

Uso de Estruturas de Dados Mais Eficientes: Atualmente, o sistema usa um array fixo, o que limita o número de páginas no histórico. O uso de uma lista dinâmica ou pilha permitiria um histórico de tamanho variável, adaptando-se melhor às necessidades do usuário.
Interface Gráfica: O sistema atualmente é baseado em texto, o que limita a experiência do usuário. Uma interface gráfica (GUI) poderia ser implementada, oferecendo uma interação mais intuitiva.
Busca no Histórico: Adicionar uma funcionalidade para pesquisar por um URL no histórico ou classificar o histórico poderia tornar o sistema mais útil, especialmente para usuários com muitos itens no histórico.
Exclusão de Páginas: A implementação de uma funcionalidade para excluir páginas específicas do histórico também pode ser uma adição útil, permitindo ao usuário gerenciar melhor o conteúdo armazenado.
Suporte a Vários Históricos: Caso o programa fosse adaptado para múltiplos usuários, seria interessante implementar uma forma de armazenar históricos distintos para cada perfil de usuário.
Com essas melhorias, o sistema pode se tornar mais completo e flexível, atendendo a um público maior e oferecendo uma experiência de navegação mais rica.
