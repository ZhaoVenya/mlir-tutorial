/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::toy::ToyIntegerType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::toy::ToyIntegerType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::toy::ToyIntegerType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::mlir::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::mlir::LogicalResult>(def)    .Case<::toy::ToyIntegerType>([&](auto t) {
      printer << ::toy::ToyIntegerType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace toy {
namespace detail {
struct ToyIntegerTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<uint64_t>;
  ToyIntegerTypeStorage(uint64_t width) : width(std::move(width)) {}

  KeyTy getAsKey() const {
    return KeyTy(width);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (width == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static ToyIntegerTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto width = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<ToyIntegerTypeStorage>()) ToyIntegerTypeStorage(std::move(width));
  }

  uint64_t width;
};
} // namespace detail
ToyIntegerType ToyIntegerType::get(::mlir::MLIRContext *context, uint64_t width) {
  return Base::get(context, std::move(width));
}

::mlir::Type ToyIntegerType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<uint64_t> _result_width;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'width'
  _result_width = ::mlir::FieldParser<uint64_t>::parse(odsParser);
  if (::mlir::failed(_result_width)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse ToyInteger parameter 'width' which is to be a `uint64_t`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_width));
  return ToyIntegerType::get(odsParser.getContext(),
      uint64_t((*_result_width)));
}

void ToyIntegerType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getWidth());
  odsPrinter << ">";
}

uint64_t ToyIntegerType::getWidth() const {
  return getImpl()->width;
}

} // namespace toy
MLIR_DEFINE_EXPLICIT_TYPE_ID(::toy::ToyIntegerType)
namespace toy {

/// Parse a type registered to this dialect.
::mlir::Type ToyDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void ToyDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace toy

#endif  // GET_TYPEDEF_CLASSES

