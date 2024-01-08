#include <pybind11/pybind11.h>
#include <podofo/podofo.h>

namespace py = pybind11;

void merge_pdfs(const char *pdfFilePath1, const char *pdfFilePath2, const char *output)
{
    PoDoFo::PdfMemDocument pdfDocument1;
    PoDoFo::PdfMemDocument pdfDocument2;

    pdfDocument1.Load(pdfFilePath1);
    pdfDocument2.Load(pdfFilePath2);

    PoDoFo::PdfPageCollection &pagetree1 = pdfDocument1.GetPages();
    PoDoFo::PdfPageCollection &pagetree2 = pdfDocument2.GetPages();

    pagetree1.InsertDocumentPageAt(pagetree1.GetCount(), pdfDocument2, 0);

    pdfDocument1.Save(output);
}

PYBIND11_MODULE(pdf_merge, m)
{
    m.def("merge_pdfs", &merge_pdfs, "Merge PDFs");
}
