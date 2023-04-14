import fitz
import os
import sys

combined = fitz.open()

for pdfFilepath in os.listdir():
    if ".pdf" in pdfFilepath:
        with fitz.open(pdfFilepath) as pdfFile:
            combined.insert_pdf(pdfFile)

combined.save(sys.argv[1])
