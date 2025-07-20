// --- IMPORTS ---
import { clubsData } from './data/clubs.js';


// --- DATA ---
const featuresData = {
    student: [
        { name: 'Club Directory', desc: 'A searchable and filterable list of all official campus clubs.' },
        { name: 'Event Calendar', desc: 'View all upcoming events from all clubs in one centralized calendar.' },
        { name: 'One-Click Registration', desc: 'Easily register for any event with a single click.' },
        { name: 'My Clubs View', desc: 'A personalized dashboard showing announcements from clubs you have joined.' },
        { name: 'Notifications', desc: 'Get notified about upcoming events and important announcements.' },
    ],
    coordinator: [
        { name: 'Member Management', desc: 'View and manage the list of students who have joined your club.' },
        { name: 'Event Creation', desc: 'Create and publish new events with details like date, time, and location.' },
        { name: 'Announcement Publisher', desc: 'Post announcements that are instantly visible to all your club members.' },
        { name: 'Registration Tracking', desc: 'Monitor how many students have registered for your events in real-time.' },
        { name: 'Club Profile Editing', desc: 'Update your club\'s description, contact info, and branding.' },
    ],
    admin: [
        { name: 'Global Dashboard', desc: 'An overview of system-wide statistics, including total users, clubs, and events.' },
        { name: 'Club Approval', desc: 'Approve or deny applications for new clubs on campus.' },
        { name: 'User Management', desc: 'Manage user roles and permissions (Student, Coordinator, Admin).' },
        { name: 'Broadcast Announcements', desc: 'Send important announcements to all users across the platform.' },
        { name: 'Data Analytics', desc: 'View analytics on club popularity and event attendance trends.' },
    ]
};


// --- DOM ELEMENTS ---
const featuresGrid = document.getElementById('features-grid');
const featureTabs = document.getElementById('feature-tabs');
const modal = document.getElementById('modal');
const modalCloseBtn = document.getElementById('modal-close-btn');
const mobileMenuBtn = document.getElementById('mobile-menu-btn');
const mobileMenu = document.getElementById('mobile-menu');
const clubsGrid = document.getElementById('clubs-grid');
const clubSearchInput = document.getElementById('club-search-input');
const clubFilterButtons = document.getElementById('club-filter-buttons');


// --- RENDER FUNCTIONS ---
function renderFeatures(category) {
    if (!featuresGrid) return;
    featuresGrid.innerHTML = '';
    featuresData[category].forEach(feature => {
        const featureCard = `
            <div class="glass-card rounded-lg p-6 transform hover:-translate-y-2 transition-transform duration-300">
                <h3 class="text-xl font-bold text-sky-400 mb-2">${feature.name}</h3>
                <p class="text-gray-400">${feature.desc}</p>
            </div>
        `;
        featuresGrid.innerHTML += featureCard;
    });
}

function renderClubs() {
    if (!clubsGrid || !clubSearchInput || !clubFilterButtons) return;

    const searchTerm = clubSearchInput.value.toLowerCase();
    const activeFilter = clubFilterButtons.querySelector('.club-filter-btn-active').dataset.category;

    const filteredClubs = clubsData.filter(club => {
        const matchesCategory = activeFilter === 'all' || club.category === activeFilter;
        const matchesSearch = club.name.toLowerCase().includes(searchTerm) || club.desc.toLowerCase().includes(searchTerm);
        return matchesCategory && matchesSearch;
    });

    clubsGrid.innerHTML = '';
    if (filteredClubs.length === 0) {
        clubsGrid.innerHTML = `<p class="text-gray-400 col-span-full text-center">No clubs found matching your criteria.</p>`;
        return;
    }

    filteredClubs.forEach(club => {
        const clubCard = `
            <div class="glass-card rounded-lg p-6 flex flex-col">
                <h3 class="text-xl font-bold text-sky-400 mb-2">${club.name}</h3>
                <p class="text-gray-400 flex-grow">${club.desc}</p>
                <div class="mt-4 pt-4 border-t border-gray-700 flex justify-between items-center">
                    <span class="text-sm font-medium text-gray-500">${club.category}</span>
                    <span class="text-sm font-semibold text-white">${club.members} Members</span>
                </div>
            </div>
        `;
        clubsGrid.innerHTML += clubCard;
    });
}

// --- MODAL LOGIC ---
function openModal() {
    if (modal) modal.style.display = 'flex';
}

function closeModal() {
    if (modal) modal.style.display = 'none';
}

// --- NAVIGATION LOGIC ---
function showPage(pageId) {
    // Hide all page sections
    document.querySelectorAll('.page-section').forEach(page => {
        page.classList.add('hidden');
    });

    const newPage = document.getElementById(`page-${pageId}`);

    if (newPage) {
        // Check if the page is a placeholder that needs the "Coming Soon" message.
        // A placeholder is defined as a page section with no child elements.
        if (newPage.children.length === 0) {
             newPage.innerHTML = `<div class="py-20 text-center"><h2 class="text-4xl font-bold text-white">Coming Soon...</h2><p class="text-gray-400 mt-4">This section is under construction.</p></div>`;
        }
        // Show the target page
        newPage.classList.remove('hidden');
    } else {
        // Fallback to home if page not found
        const homePage = document.getElementById('page-home');
        if (homePage) homePage.classList.remove('hidden');
    }
    
    // Update nav link active state
    document.querySelectorAll('#header .nav-link').forEach(link => {
        link.classList.remove('nav-link-active');
        if (link.dataset.page === pageId) {
            link.classList.add('nav-link-active');
        }
    });

    // Hide mobile menu after navigation
    if (mobileMenu && mobileMenu.offsetParent !== null) {
        mobileMenu.classList.add('hidden');
    }
    
    window.scrollTo(0, 0);
}

// --- EVENT LISTENERS ---
document.addEventListener('DOMContentLoaded', () => {
    // Initial renders
    renderFeatures('student');
    renderClubs();

    // Page navigation
    document.body.addEventListener('click', (e) => {
        const target = e.target.closest('[data-page]');
        if (target) {
            e.preventDefault();
            const pageId = target.dataset.page;
            showPage(pageId);
        }
    });

    // Modal buttons
    const demoBtns = [
        document.getElementById('demo-btn-nav'),
        document.getElementById('demo-btn-mobile'),
        document.getElementById('demo-btn-hero')
    ];
    demoBtns.forEach(btn => {
        if (btn) btn.addEventListener('click', openModal);
    });
    if (modalCloseBtn) modalCloseBtn.addEventListener('click', closeModal);
    if (modal) {
        modal.addEventListener('click', (e) => {
            if (e.target === modal) closeModal();
        });
    }

    // Mobile menu toggle
    if (mobileMenuBtn) {
        mobileMenuBtn.addEventListener('click', () => {
            if (mobileMenu) mobileMenu.classList.toggle('hidden');
        });
    }

    // Feature tabs
    if (featureTabs) {
        featureTabs.addEventListener('click', (e) => {
            if (e.target.tagName === 'BUTTON') {
                featureTabs.querySelector('.feature-tab-active').classList.replace('feature-tab-active', 'feature-tab-inactive');
                e.target.classList.replace('feature-tab-inactive', 'feature-tab-active');
                renderFeatures(e.target.dataset.category);
            }
        });
    }
    
    // Club filters
    if (clubSearchInput) {
        clubSearchInput.addEventListener('keyup', renderClubs);
    }
    if (clubFilterButtons) {
        clubFilterButtons.addEventListener('click', (e) => {
            if (e.target.tagName === 'BUTTON') {
                clubFilterButtons.querySelector('.club-filter-btn-active').classList.remove('club-filter-btn-active');
                e.target.classList.add('club-filter-btn-active');
                renderClubs();
            }
        });
    }
});