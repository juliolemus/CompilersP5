#include "codegeneration.hpp"

// CodeGenerator Visitor Functions: These are the functions
// you will complete to generate the x86 assembly code. Not
// all functions must have code, many may be left empty.
//
// NOTE: You only need to complete code for expressions,
// assignments, returns, and local variable space allocation.
// Refer to project description for exact details.

void CodeGenerator::visitProgramNode(ProgramNode* node) 
{
     node->visit_children(this);
     std::cout << "#if __APPLE__" << std::endl;
     std::cout << "   .globl _Main_main" << std::endl;
     std::cout << "#else " << std::endl;
     std::cout << "   .globl Main_main" << std::endl;
     std::cout << "#endif" << std::endl;

}

void CodeGenerator::visitClassNode(ClassNode* node) 
{
    currentClassName=node->identifier_1->name;
    currentClassInfo=(*classTable)[currentClassName];
    std::cout << "#if __APPLE__" << std::endl;
    std::cout << "  _Main_main:" << std::endl; 
    std::cout << "#else " << std::endl;
    std::cout << "   Main_main:" << std::endl;
    std::cout << "#endif" << std::endl;
    node->visit_children(this);
}

void CodeGenerator::visitMethodNode(MethodNode* node) 
{
    currentMethodName=node->identifier->name;
    currentMethodInfo=currentClassInfo.methods[currentMethodName];
    node->visit_children(this);
}

void CodeGenerator::visitMethodBodyNode(MethodBodyNode* node)
{
    std::cout << "push %ebp" << std::endl; //prologue
    std::cout << "mov %esp,%ebp" << std::endl;
    std::cout << "sub " << "$" << currentMethodInfo.localsSize << ",%esp"<<std::endl;	    
    node->visit_children(this);
    std::cout << "mov %ebp,%esp" << std::endl; //epilogue
    std::cout << "pop %ebp" << std::endl;
    std::cout << "ret" << std::endl;	 
}

void CodeGenerator::visitParameterNode(ParameterNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitDeclarationNode(DeclarationNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitReturnStatementNode(ReturnStatementNode* node) 
{
    node->visit_children(this);
}

void CodeGenerator::visitAssignmentNode(AssignmentNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %eax" << std::endl;
    std::cout << "mov %eax, " << currentMethodInfo.variables[node->identifier->name].offset << "(%ebp)" << std::endl;
}

void CodeGenerator::visitCallNode(CallNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIfElseNode(IfElseNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitForNode(ForNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitPrintNode(PrintNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitPlusNode(PlusNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %eax" << std::endl;
    std::cout << "add %ebx,%eax" << std::endl;
    std::cout << "push %eax" << std::endl;
}

void CodeGenerator::visitMinusNode(MinusNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %eax" << std::endl;
    std::cout << "sub %ebx,%eax" << std::endl;
    std::cout << "push %eax" << std::endl;
}

void CodeGenerator::visitTimesNode(TimesNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %eax" << std::endl;
    std::cout << "imul %ebx,%eax" << std::endl;
    std::cout << "push %eax" << std::endl;
}

void CodeGenerator::visitDivideNode(DivideNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %ebx" << std::endl;
    std::cout << "pop %eax" << std::endl;
    std::cout << "mov $0,%edx"<< std::endl;
    std::cout << "cdq" << std::endl;
    std::cout << "idiv %ebx" << std::endl;
    std::cout << "push %eax" << std::endl;  
}

void CodeGenerator::visitLessNode(LessNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitLessEqualNode(LessEqualNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitEqualNode(EqualNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitAndNode(AndNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitOrNode(OrNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitNotNode(NotNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitNegationNode(NegationNode* node) 
{
    node->visit_children(this);
    std::cout << "pop %eax" << std::endl;
    std::cout << "neg %eax" << std::endl;
    std::cout << "push %eax" << std::endl;
}

void CodeGenerator::visitMethodCallNode(MethodCallNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitMemberAccessNode(MemberAccessNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitVariableNode(VariableNode* node) 
{
      std::cout << "push " << currentMethodInfo.variables[node->identifier->name].offset << "(%ebp)" << std::endl;
}

void CodeGenerator::visitIntegerLiteralNode(IntegerLiteralNode* node)
{
      std::cout << "push " << "$" << node->integer->value << std::endl;
}

void CodeGenerator::visitBooleanLiteralNode(BooleanLiteralNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitNewNode(NewNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIntegerTypeNode(IntegerTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitBooleanTypeNode(BooleanTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitObjectTypeNode(ObjectTypeNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitNoneNode(NoneNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIdentifierNode(IdentifierNode* node) {
    // WRITEME: Replace with code if necessary
}

void CodeGenerator::visitIntegerNode(IntegerNode* node) {
    // WRITEME: Replace with code if necessary
}
