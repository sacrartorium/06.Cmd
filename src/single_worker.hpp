#pragma once

/**
 @file
 Заголовочный файл, описывающий работу с одной командой.
 */

#include "publisher.hpp"

struct SingleWorker : public Publisher {
  SingleWorker(size_t bulkSize);
  ~SingleWorker();

  /**
    Добавление команды.
    @param command Команда.
   */
  void addCommand(const std::string &command);

  static PublisherPtr createWorker(int bulkSize);

private:
  void openBrace() override;
  void closeBrace() override;

  void job(const std::string &command) override;

  size_t mBulkSize;
};
