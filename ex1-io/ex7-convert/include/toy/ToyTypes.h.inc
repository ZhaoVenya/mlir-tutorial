/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace toy {
class ToyIntegerType;
namespace detail {
struct ToyIntegerTypeStorage;
} // namespace detail
class ToyIntegerType : public ::mlir::Type::TypeBase<ToyIntegerType, ::mlir::Type, detail::ToyIntegerTypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "toy.int";
  static ToyIntegerType get(::mlir::MLIRContext *context, uint64_t width);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"int"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  uint64_t getWidth() const;
};
} // namespace toy
MLIR_DECLARE_EXPLICIT_TYPE_ID(::toy::ToyIntegerType)

#endif  // GET_TYPEDEF_CLASSES

