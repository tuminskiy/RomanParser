#include "converter/mainwindow.hpp"
#include "analyze.hpp"

#include <QMessageBox>

namespace rp {

MainWindow::MainWindow(QWidget* parent) : QMainWindow{ parent } {
  ui_.setupUi(this);

  connect(ui_.button_convert, &QPushButton::clicked,
          this, &MainWindow::convert_clicked);
}

MainWindow::~MainWindow() = default;

void MainWindow::convert_clicked() {
  const auto qstrs = ui_.input_text->toPlainText().simplified().toLower().split(' ');
  std::vector<std::string> strs(qstrs.size());

  std::transform(std::cbegin(qstrs), std::cend(qstrs), std::begin(strs),
    [](const QString& qstr) { return qstr.toStdString(); }
  );

  std::vector<rp::token> tokens(strs.size());
  rp::tokenize(std::cbegin(strs), std::cend(strs), std::begin(tokens));

  const auto analyze_result = rp::analyze(std::cbegin(tokens), std::cend(tokens));

  if (!analyze_result.success) {
    ui_.output_text->clear();
    QMessageBox::critical(this, "Error", QString::fromStdString(analyze_result.msg));
    return;
  }

  using namespace std::string_literals;

  const auto result = std::accumulate(std::cbegin(tokens), std::cend(tokens), ""s,
    [](const std::string& init, const rp::token& token) {
      return init + std::get<rp::number_info>(token).roman;
    }
  );

  ui_.output_text->setText(QString::fromStdString(result));
}

} // namespace rp

