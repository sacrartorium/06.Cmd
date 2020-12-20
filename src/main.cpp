#include "controller.hpp"
#include "multiple_worker.hpp"
#include "single_worker.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: invalid number of arguments." << std::endl;
    return -1;
  }

  {
    Controller controller;

    controller.setInput(&std::cin);
    controller.push(SingleWorker::createWorker(std::atoi(argv[1])));
    controller.push(MultipleWorker::createWorker());
    controller.execute();
  }
  return 0;
}
