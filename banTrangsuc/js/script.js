const bar = document.querySelector('#bar');
const close = document.querySelector('#close');
const nav = document.querySelector('#menu');

if (bar && nav) {
    bar.addEventListener('click', () => {
        nav.classList.toggle('active'); // Dùng toggle để mở/đóng menu
    });
}
if (close && nav) {
    close.addEventListener('click', () => {
        nav.classList.remove('active'); // Dùng toggle để mở/đóng menu
    });
}
