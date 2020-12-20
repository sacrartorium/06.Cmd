#include "controller.hpp"

void Controller::setInput(std::istream *stream) { mSource = stream; }

void Controller::execute() {
  std::string line;

  while (std::getline(*mSource, line)) {
    for (const auto &subscriber : mSubscribers)
      subscriber->parse(line);
  };
}

void Controller::push(PublisherPtr subscriber) {
  mSubscribers.push_back(subscriber);
}
