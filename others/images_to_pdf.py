# install these librarys
# pip install pillow
# pip install img2pdf
# pip install pikepdf


import os
import PIL
from PIL import Image
from tkinter.filedialog import *
import img2pdf
from pikepdf import Pdf
import pikepdf
import base64




def string_to_base64(string):
    return base64.b64encode(string.encode('utf-8')).decode('utf-8')


def put_password(file_path, folder_name):
    pdf = Pdf.open(file_path)
    output = folder_name+".xml"
    password = string_to_base64(output)
    pdf.save(output, encryption=pikepdf.Encryption(
        owner="@//@", user="@//@", R=4))
    pdf.close()


def image_to_pdf(path):
    images = [i for i in os.listdir(path) if i.endswith(
        ".jpg") or i.endswith(".png") or i.endswith(".jpeg")  or file.endswith(".JPG") ]
    print(images)
    os.chdir(path)
    with open("output.pdf", "wb") as f:
        f.write(img2pdf.convert(images),)


def compress_image(file_path):
    img = PIL.Image.open(file_path)
    myHeight, mywidth = img.size
    size = os.stat(file_path).st_size
    rgb_im = img.convert('RGB')
    rgb_im.save('audacious.jpg')
    img=rgb_im
    print(rgb_im)
    

    if size >= 500000:
        img = img.resize((myHeight, mywidth), PIL.Image.ANTIALIAS)
        save_path = file_path.split('.')[0] + '_.jpg'
        img.save(save_path)
        os.remove(file_path)


path = os.getcwd()
print(path)

os.chdir(path)
for file in os.listdir(path):
    if file.endswith(".jpg") or file.endswith(".png") or file.endswith(".jpeg")  or file.endswith(".JPG"):
        compress_image(path+'\\'+file)

folder_name = path.split('\\')[-1]

full_path = path+'\\output.pdf'

image_to_pdf(path)

# delete all images
for file in os.listdir(path):
    if file.endswith(".jpg") or file.endswith(".png") or file.endswith(".jpeg") or file.endswith(".JPG"):
        os.remove(file)

put_password(full_path, folder_name)
os.remove(full_path)
