// Lấy các phần tử DOM để xử lý menu
const bar = document.querySelector('#bar'); // Nút mở menu
const close = document.querySelector('#close'); // Nút đóng menu
const nav = document.querySelector('#menu'); // Menu chính

// Xử lý sự kiện mở menu
if (bar && nav) {
  bar.addEventListener('click', () => {
    nav.classList.toggle('active'); // Thêm/xóa class 'active' để mở/đóng menu
  });
}

// Xử lý sự kiện đóng menu
if (close && nav) {
  close.addEventListener('click', () => {
    nav.classList.remove('active'); // Xóa class 'active' để đóng menu
  });
}

// Hàm hiển thị tab nội dung
function showTab(tabId) {
  const tabs = document.querySelectorAll('.tab-content'); // Lấy tất cả các tab nội dung
  const buttons = document.querySelectorAll('.tab-btn'); // Lấy tất cả các nút tab

  // Ẩn tất cả các tab nội dung
  tabs.forEach(tab => tab.style.display = 'none');
  // Xóa class 'active' khỏi tất cả các nút tab
  buttons.forEach(btn => btn.classList.remove('active'));

  // Hiển thị tab được chọn
  document.getElementById(tabId).style.display = 'block';

  // Gắn class 'active' vào nút tab được click
  const clickedBtn = Array.from(buttons).find(btn => btn.textContent.includes(tabId === 'info' ? 'Thông tin' : 'Đánh giá'));
  if (clickedBtn) clickedBtn.classList.add('active');
}

// Lấy các phần tử DOM liên quan đến đánh giá
const stars = document.querySelectorAll('#starRating span'); // Các ngôi sao đánh giá
const reviewForm = document.getElementById('review-form'); // Form đánh giá
const reviewTextInput = document.getElementById('review-text'); // Input nội dung đánh giá
const nameInput = document.getElementById('name'); // Input tên người đánh giá
const emailInput = document.getElementById('email'); // Input email người đánh giá
const reviewsDisplay = document.getElementById('reviews-display'); // Khu vực hiển thị đánh giá
const reviewCount = document.getElementById('review-count'); // Hiển thị số lượng đánh giá

// Biến lưu trạng thái đánh giá
let selectedRating = 0; // Số sao được chọn
let reviews = []; // Mảng lưu trữ các đánh giá

// Xử lý sự kiện hover và click vào các ngôi sao
stars.forEach((star, index) => {
  star.addEventListener('mouseover', () => highlightStars(index)); // Hover để làm nổi bật các ngôi sao
  star.addEventListener('mouseout', resetStars); // Rời chuột để reset trạng thái hover
  star.addEventListener('click', () => {
    selectedRating = index + 1; // Cập nhật số sao được chọn
    setSelectedStars(); // Hiển thị trạng thái các ngôi sao đã chọn
  });
});

// Hàm làm nổi bật các ngôi sao khi hover
function highlightStars(index) {
  stars.forEach((star, i) => {
    star.classList.toggle('hovered', i <= index); // Thêm class 'hovered' cho các ngôi sao <= index
  });
}

// Hàm reset trạng thái hover của các ngôi sao
function resetStars() {
  stars.forEach(star => star.classList.remove('hovered')); // Xóa class 'hovered' khỏi tất cả các ngôi sao
}

// Hàm hiển thị trạng thái các ngôi sao đã chọn
function setSelectedStars() {
  stars.forEach((star, i) => {
    star.classList.toggle('selected', i < selectedRating); // Thêm class 'selected' cho các ngôi sao < selectedRating
  });
}

// Xử lý sự kiện submit form đánh giá
reviewForm.addEventListener('submit', function(e) {
  e.preventDefault(); // Ngăn chặn hành vi mặc định của form

  // Kiểm tra nếu chưa chọn số sao
  if (selectedRating === 0) {
    alert("Vui lòng chọn số sao đánh giá."); // Hiển thị thông báo
    return;
  }

  // Lấy dữ liệu từ form
  const name = nameInput.value;
  const reviewText = reviewTextInput.value;

  // Tạo đối tượng đánh giá
  const review = {
    name: name,
    text: reviewText,
    stars: selectedRating
  };

  // Thêm đánh giá vào mảng reviews
  reviews.push(review);
  // Lưu mảng reviews vào localStorage
  localStorage.setItem('reviews', JSON.stringify(reviews));
  // Hiển thị đánh giá mới
  displayReview(review);
  // Cập nhật số lượng đánh giá
  updateStats();

  // Reset form và trạng thái sao
  reviewForm.reset(); // Reset form
  console.log('Form đã reset'); // Log trạng thái reset
  selectedRating = 0; // Reset số sao đã chọn
  setSelectedStars(); // Reset trạng thái các ngôi sao
  stars.forEach(star => star.classList.remove('selected')); // Xóa class 'selected' khỏi các ngôi sao
});

// Lấy dữ liệu từ localStorage khi load trang
if (localStorage.getItem('reviews')) {
  reviews = JSON.parse(localStorage.getItem('reviews')); // Lấy mảng reviews từ localStorage
  reviews.forEach(displayReview); // Hiển thị tất cả các đánh giá
  updateStats(); // Cập nhật số lượng đánh giá
}

// Hàm hiển thị một đánh giá
function displayReview(review) {
  const reviewDiv = document.createElement('div'); // Tạo thẻ div mới
  reviewDiv.classList.add('review-card'); // Thêm class 'review-card'
  reviewDiv.innerHTML = `
    <strong>${review.name}</strong> <!-- Hiển thị tên người đánh giá -->
    <div class="stars">${'★'.repeat(review.stars)}${'☆'.repeat(5 - review.stars)}</div> <!-- Hiển thị số sao -->
    <p>${review.text}</p>`; // Hiển thị nội dung đánh giá
  reviewsDisplay.prepend(reviewDiv); // Thêm đánh giá vào đầu danh sách
}

// Hàm cập nhật số lượng đánh giá
function updateStats() {
  const count = reviews.length; // Lấy số lượng đánh giá
  reviewCount.textContent = count; // Hiển thị số lượng đánh giá
}

//
